/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2025/03/05 14:10:49 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(int height)
{
	t_map	map;

	map.arr = malloc(height);
	if (map.arr == NULL)
		exit_sl(NULL, "MALLOC_FAIL_PLACEHOLDER\n", -1); // TODO: Add a proper error message
	map.height = height;
	map.length = 0;
	map.keys = 0;
	map.exits = 0;
	map.movements = 0;
	map.mlx = NULL;
	map.win = NULL;
	map.assets.bg = NULL;
	map.assets.exit = NULL;
	map.assets.key = NULL;
	map.assets.player = NULL;
	map.assets.wall = NULL;
	map.pl.x = 0;
	map.pl.y = 0;
	return (map);
}

void	process_raw_map(t_map map, char *raw_map)
{
	int	line;
	int	last_nl;

	line = 0;
	last_nl = 0;
	ft_printf("Raw map (From read):\n%s\n\nTo map array:\n", raw_map);
	while (last_nl != -1)
	{
		last_nl = ft_strchr(raw_map, '\n');
		map.arr[line] = ft_substr(raw_map, 0, last_nl);
		raw_map = ft_substr(raw_map, last_nl + 1, ft_strlen(raw_map, 0));
		ft_printf("%s\n", map.arr[line]);
		line++;
	}
	free(raw_map);
	// exit_sl(&map, NULL, 0); TODO: Fix double free
	exit(0);
}

int	count_lines(char *raw_map)
{
	int		i;
	int		lines;

	lines = 0;
	i = 0;
	while (raw_map[i] != '\0')
	{
		if (raw_map[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

void	read_map_file(int fd, char *raw_map)
{
	int		read_res;
	char	*read_buff;
	int		len;

	if (fd < 0)
		exit_sl(NULL, MAP_OPEN_ERR, 3);
	read_res = 1;
	len = 0;
	while (read_res > 0)
	{
		read_buff = malloc(BUFFER_SIZE * sizeof(char));
		read_res = read(fd, read_buff, BUFFER_SIZE);
		len += read_res;
		if (read_res == -1)
		{
			free(raw_map);
			free(read_buff);
			exit_sl(NULL, "READ_FAIL_PLACEHOLDER\n", -1);  // TODO: Add a proper error message
		}
		raw_map = ft_strjoin(raw_map, read_buff);
		free(read_buff);
	}
	raw_map[len] = '\0';
	close(fd);
	process_raw_map(init_map(count_lines(raw_map)), raw_map);
}

/*void	read_map_file(char *map_name)
{
	int		fd;
	char	*map[MAX_MAP_HEIGHT];
	char	*current_map_line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_sl(NULL, MAP_OPEN_ERR, 3);
	i = 0;
	while (i < MAX_MAP_HEIGHT)
	{
		current_map_line = get_next_line(fd);
		if (current_map_line == NULL)
			break ;
		map[i++] = current_map_line;
	}
	current_map_line = get_next_line(fd);
	if (current_map_line != NULL)
	{
		free(current_map_line);
		close(fd);
		exit_sl(NULL, MAP_SIZE_ERR, 6);
	}
	close(fd);
	validate_map_content(create_base_map(map, i));
}*/

void	parse_map_input(char **args)
{
	int		size;
	char	*raw_map;

	size = 0;
	while (args[1][size] != '\0')
		size++;
	if (size <= 3 || args[1][size - 1] != 'r' || args[1][size - 2] != 'e'
		|| args[1][size - 3] != 'b' || args[1][size - 4] != '.')
		exit_sl(NULL, MAP_EXTENSION_ERR, 2);
	raw_map = ft_strdup("");
	if (raw_map == NULL)
		exit_sl(NULL, "MALLOC_FAIL_PLACEHOLDER\n", -1);
	return (read_map_file(open(args[1], O_RDONLY), raw_map));
}
