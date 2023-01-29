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

void	panic(t_pipex *data, char *error_msg, int exit_status)
{
	if (data)
		destroy(data);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(exit_status);
}
