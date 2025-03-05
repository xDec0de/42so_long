/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:30 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:28:14 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_utils.h"

size_t	sl_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t			i;
	unsigned int	cont;

	i = 0;
	cont = 0;
	while (src[cont] != '\0')
		cont++;
	if (dstsize == 0)
		return (cont);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (cont);
}
