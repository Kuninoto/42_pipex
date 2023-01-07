/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:56:27 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 23:05:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

t_redirs	get_rdrs(int argc, char **argv)
{
	t_redirs	rdrs;

	rdrs.infile_fd = open(argv[1], O_RDONLY);
	if (rdrs.infile_fd == -1)
		panic(ERR_INFILE, 128);
	rdrs.outfile_fd = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (rdrs.outfile_fd == -1)
		panic(ERR_OUTFILE, 128);
	return (rdrs);
}

char	**get_paths(char **envp)
{
	size_t	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
		i += 1;
	return (ft_split(envp[i], ':'));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		data;

	if (argc != 5)
		panic("Invalid number of arguments", EXIT_FAILURE);
	init_data(argc, argv, envp, &data);
	for (int i = 0; i < data.nbr_of_cmds; i += 1)
	{
		for (int j = 0; argv[j] != NULL; j += 1)
			printf("%s ", data.cmd_list[i].argv[j]);
		printf("\n");
	}
	destroy_pipex(&data);
	exit(EXIT_SUCCESS);
	exec_pipe(&data, envp);
	return (EXIT_SUCCESS);
}


/* HANDLE MULTIPLE CMDS, SEGFAULTING ON MANDATORY INPUT.*/