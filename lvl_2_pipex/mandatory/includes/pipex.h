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

# include "libft.h"
# include <sys/wait.h> // wait(), waitpid()
# include <fcntl.h> // open(), access()

// ERROR MESSAGES
# define INVALID_NBR_ARGS "Invalid number of arguments"

# define INFILE_ERR "Unable to open infile file descriptor"
# define OUTFILE_ERR "Unable to open outfile file descriptor"

# define FORK_ERR "fork() failed"
# define PIPE_ERR "pipe() failed"

# define CMD_NOT_FOUND "command not found"

typedef struct s_command {
	int		argc;
	char	**argv;
}				t_cmd;

typedef struct s_pipex {
	char	**envp;
	char	**paths;
	t_cmd	l_cmd;
	t_cmd	r_cmd;
	int		infile_fd;
	int		outfile_fd;
}				t_pipex;

t_pipex	init_data(char **argv, char **envp);
void	exec_pipe(t_pipex *data);
/* Frees commands' argv's and paths */
void	destroy(t_pipex *data);
/* Calls destroy() on data, prints "Error:<error_msg>\n" 
to STDERR and exits the program on exit_status */
void	panic(t_pipex *data, char *error_msg, int exit_status);

#endif