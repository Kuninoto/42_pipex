/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:05:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/29 03:18:28 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/wait.h> // wait(), waitpid()
# include <fcntl.h> // open(), access()
# include <string.h> // strerror()
# include <errno.h>

// ERROR MESSAGES
# define INVALID_ARGC "Invalid number of arguments"

# define FORK_ERR "fork() failed"
# define PIPE_ERR "pipe() failed"

# define CMD_NOT_FOUND "command not found"

# define READ_END 0
# define WRITE_END 1

typedef struct s_command {
	int		argc;
	char	**argv;
}				t_cmd;

typedef struct s_pipex {
	char	**envp;
	char	**paths;
	t_cmd	left_cmd;
	t_cmd	right_cmd;
	int		infile_fd;
	int		outfile_fd;
}				t_pipex;

t_pipex	init_data(char **argv, char **envp);
int		exec_pipe(t_pipex *data);

void	destroy(t_pipex *data);

void	panic(t_pipex *data, char *error_msg, int exit_status);

#endif // PIPEX_H