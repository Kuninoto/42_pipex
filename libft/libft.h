/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:35:12 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/25 23:13:41 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

# include "writers/writers.h"
# include "inlines/inlines.h"
# include "inlines/inlines2.h"

// DEBUG UTILS ---------------------------------------

void		print_int_array(int *array, size_t len);
void		print_char_matrix(char **matrix);

// FT_DPRINTF --------------------------------------

/* Prints formatted output to a given fd */
int			ft_dprintf(int fd, const char *__format, ...);
int			prt_str(int fd, char const *str);
int			prt_ptr(int fd, void *ptr_addr);
int			prt_int(int fd, int n);
int			prt_unsigned(int fd, unsigned int nbr);
int			prt_hexa(int fd, unsigned int nbr, bool upper_case);

// MEMORY --------------------------------------------------------------------

/* Frees all elements in the matrix and its pointer */
void		free_matrix(char **matrix);
void		ft_bzero(void *ptr, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *ptr, int x, size_t n);
size_t		matrix_len(char **matrix);

// STRING --------------------------------------------------------------------
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
/* Return a literal copy of to_copy (useful when
you want to free to_copy for some reason) */
char		*ft_strcpy(char *to_copy);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strnstr(const char *big, const char *little,
				size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
/* Returns true if str is only composed by digits */
bool		is_all_digits(const char *str);
bool		is_alnum(const int c);
int			is_alpha(const int c);
bool		is_only_digits(const char *str);
bool		is_only_spaces(const char *str);
bool		is_onstr(const char *str, int c);
/* Returns s1+s2, creating a new string and frees both s1 and s2 */
char		*join_free_both(char *s1, char *s2);
/* Returns s1+s2, creating a new string, and frees s1  */
char		*join_free(char *s1, char *s2);
/* Returns s1+s2, creating a new string, and frees s2 */
char		*join_freev2(char *s1, const char *s2);
/* Returns true if str is only composed by spaces */
bool		only_spaces(const char *str);
/* Checks if both strings passed as parameters are absolutely equal */
bool		streq(char *str1, char *str2);
char		*trim_free(char *s1, char const *set);

// TYPE_CONVERSIONS-----------------------------------------

bool		fits_in_longlong(char *str);
/* Converts a string to an integer */
int			ft_atoi(const char *str);
/* Converts a string to a ssize_t */
ssize_t		ft_atol(const char *str);
/* Converts a string to a long long */
long long	ft_atoll(const char *str);
char		*ft_itoa(int n);
char		*ft_lltoa(long long n);
char		*ft_ltoa(ssize_t n);
char		*ft_utoa(unsigned int n);

// WRITERS -------------------------------------

void		ft_putnbr_fd(int n, int fd);

// GET_NEXT_LINE ---------------------------------
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif 

/**
 * @brief Returns a line, ending in newline (if any),
 * 		  read from a file descriptor
 * 
 * @param fd File descriptor to read from
 */
char		*get_next_line(int fd);

#endif // LIBFT_H
