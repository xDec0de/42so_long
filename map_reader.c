/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2025/03/04 15:23:42 by daniema3         ###   ########.fr       */
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

t_map	create_base_map(char **map, int map_height)
{
	t_map		res;

	res.arr = map;
	res.height = map_height;
	res.exits = 0;
	res.keys = 0;
	res.movements = 0;
	return (res);
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
	if (size <= 3 || args[1][size - 1] != 'r' || args[1][size - 2] != 'e'
		|| args[1][size - 3] != 'b' || args[1][size - 4] != '.')
		return (2);
	return (read_map_file(args[1]));
}
