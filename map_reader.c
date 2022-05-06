/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2022/05/06 17:57:04 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(char **map, int map_size)
{
	int	i;

	i = 0;
	while (i <= map_size)
	{
		free(map[i]);
		i++;
	}
	*map = NULL;
	return ;
}

int	parse_map_content(char **map, int map_size)
{
	print_map(map, map_size);
	map_free(map, map_size);
	return (0);
}

int	read_map_file(char *map_name)
{
	int		fd;
	int		map_length;
	char	*map[MAX_MAP_SIZE];
	char	*current_map_line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (3);
	i = 0;
	map[i] = get_next_line(fd);
	if (map[i] == NULL)
		return (4);
	map_length = ft_strlen(map[i]);
	current_map_line = get_next_line(fd);
	while (current_map_line != NULL)
	{
		i++;
		map[i] = current_map_line;
		current_map_line = get_next_line(fd);
	}
	free(current_map_line);
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
