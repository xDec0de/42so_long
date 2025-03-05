/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:48:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:33:34 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_utils.h"

char	*sl_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = sl_calloc(sl_strlen(s, 0) + 1);
	if (s == NULL || str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
