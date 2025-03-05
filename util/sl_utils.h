/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:44:58 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:32:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SL_UTILS_H
# define SL_UTILS_H

# include "printf/ft_printf.h"

char	*sl_calloc(int amount);

int		sl_strchr(char *s, char ch);

char	*sl_strdup(char *s);

/**
 * @brief Joins two strings (`s1` and `s2`). Optionally
 * freeing both strings.
 * 
 * @param s1 The first string, will be at the beginning of
 * the new string.
 * @param s2 The second string, will be appeneded to `s2` on
 * a new string.
 * @param free_strs Whether to free `s1` and `s2` or not.
 * 
 * @return A new string allocated with `malloc`. The
 * length of this string will be the length of `s1` + `s2`,
 * reserving one extra space to null-terminate the string.
 * `NULL` will be returned if either `s1` or `s2` are `NULL`,
 * or if `malloc` fails to allocate the new string.
 */
char	*sl_strjoin(char *s1, char *s2, int free_strs);

size_t	sl_strlcpy(char *dest, const char *src, size_t dstsize);

int		sl_strlen(const char *str, int ignore_new_line);

char	*sl_substr(char *s, int start, int len);

#endif
