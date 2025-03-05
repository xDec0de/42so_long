/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:31:38 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:31:50 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_utils.h"

char	*sl_calloc(int amount)
{
	char	*res;

	res = malloc(amount * sizeof(char));
	if (res == NULL)
		return (NULL);
	amount--;
	while (amount >= 0)
	{
		res[amount] = '\0';
		amount--;
	}
	return (res);
}
