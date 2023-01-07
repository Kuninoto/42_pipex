/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:56:27 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 21:38:18 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

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
	exec_pipe(&data, envp);
	destroy_pipex(&data);
	return (EXIT_SUCCESS);
}
