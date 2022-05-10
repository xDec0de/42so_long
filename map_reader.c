/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2022/05/10 13:11:44 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_free(char **map, int map_height, int return_value)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		free(map[i]);
		i++;
	}
	*map = NULL;
	return (return_value);
}

int	validate_map_structure(t_map map)
{
	int	i;
	int	j;

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
	return (validate_map_objects(&map, 0));
}

int	validate_map_content(t_map map)
{
	int	i;
	int	j;

	map.length = ft_strlen(map.arr[0], 1);
	i = 1;
	while (i < map.height)
	{
		j = 0;
		if (ft_strlen(map.arr[i], 1) != map.length)
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
	else if (map.length > 1024)
		return (map_free(map.arr, map.height, 6));
	return (validate_map_structure(map));
}

int	read_map_file(char *map_name)
{
	int		fd;
	char	*map[1024];
	char	*current_map_line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (3);
	i = 0;
	while (i < 1024)
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
