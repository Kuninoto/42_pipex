/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:03:43 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/29 02:19:32 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Calls destroy() on <data>, prints "pipex: error: <error_msg>\n"
to STDERR and exits the program on <exit_status> */
void	panic(t_pipex *data, char *error_msg, int exit_status)
{
	if (data)
		destroy(data);
	if (error_msg)
		ft_dprintf(STDERR_FILENO, "pipex: error: %s\n", error_msg);
	exit(exit_status);
}
