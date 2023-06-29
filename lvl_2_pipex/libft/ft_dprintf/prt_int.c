/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:44:02 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/27 18:10:25 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

static void	put_int(int fd, int n)
{
	static char	digits[10] = "0123456789";

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else
	{
		if (n > 9)
			put_int(fd, n / 10);
		write(fd, &digits[n % 10], 1);
	}
}

int	prt_int(int fd, int n)
{
	put_int(fd, n);
	return (count_digits(n));
}
