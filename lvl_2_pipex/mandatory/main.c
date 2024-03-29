/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:56:27 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/29 03:08:15 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		pipe_exit_status;

	if (argc != 5)
		panic(NULL, INVALID_ARGC, EXIT_FAILURE);
	data = init_data(argv, envp);
	pipe_exit_status = exec_pipe(&data);
	destroy(&data);
	return (pipe_exit_status);
}
