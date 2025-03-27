/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:01:49 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/23 23:14:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rev_print(int fd, char *hexa)
{
	int	len;
	int	rtrn;

	len = ft_strlen(hexa) - 1;
	rtrn = 0;
	while (len >= 0)
		rtrn += write(fd, &hexa[len--], 1);
	return (--rtrn);
}

static int	hexa_convptr(int fd, unsigned long addr)
{
	int		i;
	int		temp;
	char	hexa[42];

	i = 0;
	while (addr != 0)
	{
		temp = addr % 16;
		if (temp < 10)
			hexa[i++] = temp + 48;
		else
			hexa[i++] = temp + 87;
		addr = addr / 16;
	}
	hexa[i] = '\0';
	return (rev_print(fd, hexa) + 1);
}

int	prt_ptr(int fd, void *ptr_addr)
{
	if (ptr_addr == 0)
		return (write(fd, "(nil)", 5));
	write(fd, "0x", 2);
	return (hexa_convptr(fd, (unsigned long int)ptr_addr) + 2);
}
