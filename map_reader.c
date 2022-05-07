/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2022/05/07 12:12:02 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_free(char **map, int map_size, int return_value)
{
	int	i;

	i = 0;
	printf("\n\e[1;31mAttempting map free \e[1;30m(\e[0;36msize \e[1;34m%d\e[1;30m):\n", map_size);
	while (i < map_size)
	{
		printf("\e[0;32m%d\e[1;30m: \e[0;37m%s", i, map[i]);
		free(map[i]);
		i++;
	}
	printf("\e[0m\n");
	*map = NULL;
	return (return_value);
}

int	parse_map_content(char **map, int map_size)
{
	print_map(map, map_size);
	map_free(map, map_size, 0);
	return (0);
}

int	read_map_file(char *map_name)
{
	int		fd;
	char	*map[MAX_MAP_SIZE];
	char	*current_map_line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (3);
	i = 0;
	while (i < MAX_MAP_SIZE)
	{
		current_map_line = get_next_line(fd);
		if (current_map_line == NULL)
			break ;
		map[i] = current_map_line;
		i++;
	}
	current_map_line = get_next_line(fd);
	if (current_map_line != NULL)
	{
		free(current_map_line);
		return (map_free(map, i, 6));
	}
	return (parse_map_content(map, i));
}

int	parse_map_input(char **args)
{
	int		size;

	size = 0;
	while (args[1][size] != '\0')
		size++;
	if (size <= 4 || args[1][size - 1] != 'r' || args[1][size - 2] != 'e'
		|| args[1][size - 3] != 'b' || args[1][size - 4] != '.')
		return (2);
	return (read_map_file(args[1]));
}
