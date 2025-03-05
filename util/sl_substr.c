/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:29:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:33:20 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_utils.h"

char	*sl_substr(char *s, int start, int len)
{
	char	*substr;
	int		size;

	if (s == NULL)
		return (NULL);
	if (sl_strlen(s, 0) < start)
		return (sl_strdup(""));
	size = sl_strlen(&s[start], 0);
	if (size < len)
		len = size;
	if (len + 1 > len)
		substr = sl_calloc(len + 1);
	else
		substr = sl_calloc(len);
	if (substr == NULL)
		return (NULL);
	sl_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
