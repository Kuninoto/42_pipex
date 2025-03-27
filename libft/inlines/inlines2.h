/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlines2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:57:11 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/25 23:12:57 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INLINES2_H
# define INLINES2_H

static inline int	ft_toupper(const int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static inline int	ft_tolower(const int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

static inline bool	is_print(const int c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}

static inline bool	is_ascii(const int c)
{
	if (c >= 0 && c <= 127)
		return (true);
	return (false);
}

#endif // INLINES2_H
