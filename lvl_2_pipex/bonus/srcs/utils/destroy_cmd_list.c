/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cmd_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:26:14 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 22:54:20 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	destroy_cmd_list(t_cmd *cmd_list, int nbr_of_cmds)
{
	int	i;

	i = 0;
	while (i < nbr_of_cmds)
	{
		free_matrix(cmd_list[i].argv);
		i += 1;
	}
}