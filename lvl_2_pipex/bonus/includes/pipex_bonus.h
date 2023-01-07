/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:05:26 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 23:00:31 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

size_t		get_nbr_args(char **simple_cmd);

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
	int			nbr_of_cmds;
	t_cmd		*cmd_list;
	t_redirs	rdrs;
	char		**paths;
}				t_pipex;

t_cmd	*init_cmd_list(char **argv, int nbr_of_cmds);

/* Get infile and outfile respective file descriptors.
Exit the program if any of those couldn't be opened */
t_redirs	get_rdrs(int argc, char **argv);

/* Produce a 2D array based on PATH env variable splitted on ':' */
char		**get_paths(char **envp);

static inline void	init_data(int argc, char **argv, char **envp, t_pipex *data)
{
	data->nbr_of_cmds = argc - 3;
	data->cmd_list = init_cmd_list(argv, data->nbr_of_cmds);
	data->rdrs = get_rdrs(argc, argv);
	data->paths = get_paths(envp);
}

void		exec_pipe(t_pipex *data, char **envp);

// UTILS ------------------------------------

void	destroy_cmd_list(t_cmd *cmd_list, int nbr_of_cmds);

static inline void	destroy_pipex(t_pipex *data)
{
	destroy_cmd_list(data->cmd_list, data->nbr_of_cmds);
	free_matrix(data->paths);
}


#endif