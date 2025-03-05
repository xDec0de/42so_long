/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:25:35 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:33:30 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_utils.h"

char	*sl_strjoin(char *s1, char *s2, int free_strs)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = sl_calloc(sl_strlen(s1, 0) + sl_strlen(s2, 0) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		join[i + j] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	if (free_strs)
		return (free(s1), free(s2), join);
	return (join);
}
