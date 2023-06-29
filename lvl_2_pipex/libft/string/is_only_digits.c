/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:27:42 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/01/31 00:27:43 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_only_digits(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (false);
		i += 1;
	}
	return (true);
}
