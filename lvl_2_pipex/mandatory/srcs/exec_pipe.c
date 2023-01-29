/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:32:15 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/29 03:01:07 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_bin_path(char *cmd, char **paths)
{
	size_t	i;
	char	*tmp;
	char	*bin_path;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		bin_path = join_free(tmp, cmd);
		if (access(bin_path, F_OK) == 0)
			return (bin_path);
		free(bin_path);
		i += 1;
	}
	return (NULL);
}

static void	exec_cmd(t_cmd *cmd, t_pipex *data)
{
	char	*bin_path;
	bool	absolute_path;

	if (cmd->argv[0][0] == '.' || cmd->argv[0][0] == '/')
	{
		bin_path = cmd->argv[0];
		absolute_path = true;
	}
	else
		bin_path = get_bin_path(cmd->argv[0], data->paths);
	if (!bin_path)
		panic(data, CMD_NOT_FOUND, 127);
	if (execve(bin_path, cmd->argv, data->envp) == -1)
	{
		destroy(data);
		free(bin_path);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (!absolute_path)
		free(bin_path);
	exit(EXIT_SUCCESS);
}

static void	left_side(int *pipedes, t_pipex *data)
{
	dup2(pipedes[1], STDOUT_FILENO);
	close(pipedes[0]);
	close(pipedes[1]);
	dup2(data->infile_fd, STDIN_FILENO);
	exec_cmd(&data->l_cmd, data);
}

static void	right_side(int *pipedes, t_pipex *data)
{
	dup2(pipedes[0], STDIN_FILENO);
	close(pipedes[0]);
	close(pipedes[1]);
	dup2(data->outfile_fd, STDOUT_FILENO);
	exec_cmd(&data->r_cmd, data);
}

//	bytes written on pipedes[1] can be read on pipedes[0]
void	exec_pipe(t_pipex *data)
{
	int		pipedes[2];
	pid_t	left_child;
	pid_t	right_child;

	if (pipe(pipedes) == -1)
		panic(data, PIPE_ERR, EXIT_FAILURE);
	left_child = fork();
	if (left_child == -1)
		panic(data, FORK_ERR, EXIT_FAILURE);
	if (left_child == 0)
		left_side(pipedes, data);
	right_child = fork();
	if (right_child == -1)
		panic(data, FORK_ERR, EXIT_FAILURE);
	if (right_child == 0)
		right_side(pipedes, data);
	close(pipedes[0]);
	close(pipedes[1]);
	waitpid(left_child, NULL, 0);
	waitpid(right_child, NULL, 0);
}
