/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_debugger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:36:55 by danimart          #+#    #+#             */
/*   Updated: 2022/05/07 11:14:14 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	printf("\n\e[1;31mLeak report\e[1;30m:\n\e[0;36m\n");
	system("leaks so_long | grep leaked");
	printf("\e[0m\n");
}

void	print_map(char **map, int map_size)
{
	int	i;

	i = 0;
	printf("\n\e[1;31mFinal map read \e[1;30m(\e[0;36msize \e[1;34m%d\e[1;30m):\n", map_size);
	while (i < map_size)
	{
		printf("\e[0;32m%d\e[1;30m: \e[0;37m%s", i, map[i]);
		i++;
	}
	printf("\e[0m\n");
}
