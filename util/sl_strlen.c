/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:43:19 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 17:44:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	sl_strlen(const char *str, int ignore_new_line)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if ((ignore_new_line == 1 && str[i] != '\n') || ignore_new_line != 1)
			res++;
		i++;
	}
	return (res);
}
