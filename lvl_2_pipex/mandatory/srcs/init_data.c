/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:08:35 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/29 03:18:14 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Produce a 2D array based on PATH env variable splitted on ':' */
static char	**get_paths(char **envp)
{
	size_t	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
		i += 1;
	return (ft_split(&envp[i][4], ':'));
}

static size_t	get_nbr_args(char **cmd_argv)
{
	size_t	i;

	i = 0;
	while (cmd_argv[i])
		i += 1;
	return (i);
}

/* Initializes a t_cmd type variable */
static t_cmd	init_cmd(char *cmd)
{
	t_cmd	simple_cmd;

	simple_cmd.argv = ft_split(cmd, ' ');
	simple_cmd.argc = get_nbr_args(simple_cmd.argv);
	return (simple_cmd);
}

t_pipex	init_data(char **argv, char **envp)
{
	t_pipex	data;

	data.paths = get_paths(envp);
	data.envp = envp;
	data.l_cmd = init_cmd(argv[2]);
	data.r_cmd = init_cmd(argv[3]);
	data.infile_fd = open(argv[1], O_RDONLY);
	if (data.infile_fd == -1)
		panic(&data, INFILE_ERR, 128);
	data.outfile_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (data.outfile_fd == -1)
		panic(&data, OUTFILE_ERR, 128);
	return (data);
}
