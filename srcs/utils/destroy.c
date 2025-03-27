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

/* Frees allocated memory and closes the opened file descriptors */
void	destroy(t_pipex *data)
{
	if (data->infile_fd != -1)
		close(data->infile_fd);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	if (data->paths)
		free_matrix(data->paths);
	if (data->left_cmd.argv)
		free_matrix(data->left_cmd.argv);
	if (data->right_cmd.argv)
		free_matrix(data->right_cmd.argv);
}
