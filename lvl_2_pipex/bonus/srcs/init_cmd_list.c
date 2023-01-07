/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:35:07 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 23:00:34 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

#define PIPE '|'

t_cmd	*init_cmd_list(char **argv, int nbr_of_cmds)
{
	t_cmd	*cmd_list;
	int		i;
	int		j;

	cmd_list = malloc((nbr_of_cmds) * sizeof(t_cmd));
	i = 0;
	j = 2;
	while (i < nbr_of_cmds)
	{
		if (argv[j][0] == PIPE)
		{
			j += 1;
			continue;
		}
		cmd_list[i] = init_cmd(argv[j]);
		i += 1;
		j += 1;
	}
	return (cmd_list);
}
