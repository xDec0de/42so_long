/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2022/05/08 16:23:31 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_free(char **map, int map_height, int return_value)
{
	int	i;

	i = 0;
	printf("\n\e[1;31mMap free debug \e[1;30m(\e[0;36mheight \e[1;34m%d\e[1;30m):\n", map_height);
	while (i < map_height)
	{
		printf("\e[0;32m%d\e[1;30m: \e[0;37m%s", i, map[i]);
		free(map[i]);
		i++;
	}
	printf("\e[0m\n");
	*map = NULL;
	return (return_value);
}

int	validate_map_structure(t_map map)
{
	int	i;
	int	j;

	if (map.height < 4 || map.length < 4)
		return (map_free(map.arr, map.height, 8));
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length && (i == 0 || i == map.height - 1))
		{
			if (map.arr[i][j] != '1')
				return (map_free(map.arr, map.height, 9));
			j++;
		}
		if (map.arr[i][0] != '1' || map.arr[i][map.length - 1] != '1')
			return (map_free(map.arr, map.height, 9));
		i++;
	}
	return (validate_map_objects(map, 0));
}

int	validate_map_content(t_map map)
{
	int	i;
	int	j;

	i = 0;
	map.length = 0;
	while (i < map.height)
	{
		j = 0;
		if (i == 0)
			map.length = ft_strlen(map.arr[i], 1);
		else if (ft_strlen(map.arr[i], 1) != map.length)
			return (map_free(map.arr, map.height, 7));
		while (map.arr[i][j] != '\0' && map.arr[i][j] != '\n')
		{
			if (map.arr[i][j] != '0' && map.arr[i][j] != '1'
				&& map.arr[i][j] != 'C' && map.arr[i][j] != 'E'
				&& map.arr[i][j] != 'P')
				return (map_free(map.arr, map.height, 4));
			j++;
		}
		i++;
	}
	if (map.height == 0 || map.length == 0)
		return (map_free(map.arr, map.height, 5));
	return (validate_map_structure(map));
}

int	read_map_file(char *map_name)
{
	int		fd;
	char	*map[MAX_MAP_HEIGHT];
	char	*current_map_line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (3);
	i = 0;
	while (i < MAX_MAP_HEIGHT)
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
	return (validate_map_content(create_base_map(map, i)));
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
