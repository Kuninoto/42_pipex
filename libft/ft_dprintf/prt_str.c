/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:08:11 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/23 23:15:02 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	prt_str(int fd, char const *str)
{
	if (str == NULL)
		return (write(fd, "(null)", 6));
	else
		return (write(fd, str, ft_strlen(str)));
}
