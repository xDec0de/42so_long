/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2022/05/06 13:45:23 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_file(char *map_name)
{
	int		fd;
	int		map_length;
	char	*first_line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (3);
	first_line = get_next_line(fd);
	if (first_line == NULL)
		return (4);
	map_length = ft_strlen(first_line);
	return (0);
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
