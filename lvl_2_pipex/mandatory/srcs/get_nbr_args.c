/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:46:46 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/07 20:19:33 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	get_nbr_args(char **cmd)
{
	size_t	nbr_args;
	size_t	i;

	nbr_args = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		nbr_args += 1;
		i += 1;
	}
	return (nbr_args);
}