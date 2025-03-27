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

#include "pipex.h"

//	Searches on the PATH environment
//	variable's paths for the correct path to the binary of the
//	input command
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

//	Searches for the commands' binary paths
//	(get_bin_path() or uses the literal input
//	in case it is already a path) and executes them
static void	exec_cmd(t_cmd *cmd, t_pipex *data)
{
	char	*bin_path;
	bool	is_a_path;

	if (cmd->argv[0][0] == '.' || cmd->argv[0][0] == '/')
	{
		is_a_path = true;
		bin_path = cmd->argv[0];
	}
	else
		bin_path = get_bin_path(cmd->argv[0], data->paths);
	if (!bin_path)
	{
		ft_dprintf(STDERR_FILENO, "%s: command not found\n", cmd->argv[0]);
		panic(data, NULL, 127);
	}
	if (execve(bin_path, cmd->argv, data->envp) == -1)
	{
		free(bin_path);
		panic(data, NULL, 127);
	}
	if (!is_a_path)
		free(bin_path);
	exit(EXIT_SUCCESS);
}

// Handles the left side of a pipe
static void	left_side(int *pipedes, t_pipex *data)
{
	dup2(pipedes[WRITE_END], STDOUT_FILENO);
	close(pipedes[READ_END]);
	close(pipedes[WRITE_END]);
	dup2(data->infile_fd, STDIN_FILENO);
	exec_cmd(&data->left_cmd, data);
}

// Handles the right side of a pipe
static void	right_side(int *pipedes, t_pipex *data)
{
	dup2(pipedes[READ_END], STDIN_FILENO);
	close(pipedes[READ_END]);
	close(pipedes[WRITE_END]);
	dup2(data->outfile_fd, STDOUT_FILENO);
	exec_cmd(&data->right_cmd, data);
}

int	exec_pipe(t_pipex *data)
{
	int		pipedes[2];
	pid_t	left_child_pid;
	pid_t	right_child_pid;
	int		exit_status;

	if (pipe(pipedes) == -1)
		panic(data, PIPE_ERR, EXIT_FAILURE);
	left_child_pid = fork();
	if (left_child_pid == -1)
		panic(data, FORK_ERR, EXIT_FAILURE);
	else if (left_child_pid == 0)
		left_side(pipedes, data);
	right_child_pid = fork();
	if (right_child_pid == -1)
		panic(data, FORK_ERR, EXIT_FAILURE);
	else if (right_child_pid == 0)
		right_side(pipedes, data);
	close(pipedes[READ_END]);
	close(pipedes[WRITE_END]);
	waitpid(left_child_pid, &exit_status, WUNTRACED);
	waitpid(right_child_pid, &exit_status, WUNTRACED);
	return (WEXITSTATUS(exit_status));
}
