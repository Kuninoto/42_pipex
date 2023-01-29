/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:20:14 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/29 03:18:58 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	destroy(t_pipex *data)
{
	if (data->paths)
		free_matrix(data->paths);
	if (data->l_cmd.argv)
		free_matrix(data->l_cmd.argv);
	if (data->r_cmd.argv)
		free_matrix(data->r_cmd.argv);
}
