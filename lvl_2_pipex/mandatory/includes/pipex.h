/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:05:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 22:53:29 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/libft.h"
# include <sys/wait.h> // wait() waitpid()

// CONSTANTS
# define SPACE ' '

// ERROR MESSAGES
# define ERR_INFILE "Unable to open infile file descriptor"
# define ERR_OUTFILE "Unable to open outfile file descriptor"
# define ERR_PIPE "Failed to pipe"

typedef struct s_command {
	size_t	argc;
	char	**argv;
}				t_cmd;

size_t		get_nbr_args(char **cmd);

/* Initializes a t_command type variable */
static inline t_cmd	init_cmd(char *cmd)
{
	t_cmd	simple_cmd;

	simple_cmd.argv = ft_split(cmd, SPACE);
	simple_cmd.argc = get_nbr_args(simple_cmd.argv);
	return (simple_cmd);
}

typedef struct s_redirs {
	int		infile_fd;
	int		outfile_fd;
}				t_redirs;

typedef struct s_pipex {
	t_cmd		l_cmd;
	t_cmd		r_cmd;
	t_redirs	rdrs;
	char		**paths;
}				t_pipex;

/* Get infile and outfile respective file descriptors.
Exit the program if any of those couldn't be opened */
t_redirs	get_rdrs(int argc, char **argv);

/* Produce a 2D array based on PATH env variable splitted on ':' */
char		**get_paths(char **envp);

static inline void	init_data(int argc, char **argv, char **envp, t_pipex *data)
{
	data->l_cmd = init_cmd(argv[2]);
	data->r_cmd = init_cmd(argv[3]);
	data->rdrs = get_rdrs(argc, argv);
	data->paths = get_paths(envp);
}

void		exec_pipe(t_pipex *data, char **envp);

// UTILS ------------------------------------

static inline void	destroy_pipex(t_pipex *data)
{
	free_matrix(data->l_cmd.argv);
	free_matrix(data->r_cmd.argv);
	free_matrix(data->paths);
}

#endif