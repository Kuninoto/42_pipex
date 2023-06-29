/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:12:41 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/25 23:13:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INLINES_H
# define INLINES_H

static inline bool	is_spaces(const char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

static inline int	ft_isalpha(const int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= 'a' && c <= 'z'))
		return (2);
	return (0);
}

static inline bool	is_digit(const int c)
{
	if ((c >= '0' && c <= '9'))
		return (true);
	return (false);
}

static inline bool	ft_isalnum(const int c)
{
	if (ft_isalpha(c) || is_digit(c))
		return (true);
	return (false);
}

#endif // INLINES_H
