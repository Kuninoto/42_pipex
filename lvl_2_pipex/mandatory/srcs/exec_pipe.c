/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:32:15 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 21:30:27 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_bin_path(char *cmd, char **paths)
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

void	exec_cmd(t_cmd *cmd, t_pipex *data, char **envp)
{
	char	*bin_path;

	bin_path = get_bin_path(cmd->argv[0], data->paths);
	if (bin_path == NULL || execve(bin_path, cmd->argv, envp) == -1)
	{
		ft_printf("%s: command not found\n", cmd->argv[0]);
		free(bin_path);
		destroy_pipex(data);
		exit(127);
	}
	free(bin_path);
}

void	left_side(int *pipedes, t_pipex *data, char **envp)
{
	dup2(pipedes[1], STDOUT_FILENO);
	close(pipedes[0]);
	close(pipedes[1]);
	exec_cmd(&data->l_cmd, data, envp);
}

void	right_side(int *pipedes, t_pipex *data, char **envp)
{
	dup2(pipedes[0], STDIN_FILENO);
	close(pipedes[1]);
	dup2(data->rdrs.outfile_fd, STDOUT_FILENO);
	exec_cmd(&data->r_cmd, data, envp);
}

//	bytes written on pipedes[1] can be read on pipedes[0]
void	exec_pipe(t_pipex *data, char **envp)
{
	int		pipedes[2];
	pid_t	left_child;
	pid_t	right_child;

	if (pipe(pipedes) == -1)
		panic(ERR_PIPE, EXIT_FAILURE);
	left_child = fork();
	if (left_child == 0)
		left_side(&pipedes[0], data, envp);
	right_child = fork();
	if (right_child == 0)
		right_side(&pipedes[0], data, envp);
	close(pipedes[0]);
	close(pipedes[1]);
	waitpid(left_child, NULL, 0);
	waitpid(right_child, NULL, 0);
}
