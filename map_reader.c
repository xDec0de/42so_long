/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2025/03/05 19:46:18 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(int height)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		exit_sl(NULL, MALLOC_ERR, MALLOC_ERRC);
	map->arr = malloc((height + 1) * sizeof(char *));
	if (map->arr == NULL)
		exit_sl(NULL, MALLOC_ERR, MALLOC_ERRC);
	map->verify_arr = NULL;
	map->height = height;
	map->length = 0;
	map->keys = 0;
	map->exits = 0;
	map->movements = 0;
	map->mlx = NULL;
	map->win = NULL;
	map->assets.bg = NULL;
	map->assets.exit = NULL;
	map->assets.key = NULL;
	map->assets.player = NULL;
	map->assets.wall = NULL;
	map->pl.x = 0;
	map->pl.y = 0;
	return (map);
}

void	process_raw_map(t_map *map, char *raw_map)
{
	int		line;
	int		last_nl;
	char	*tmp;

	line = 0;
	last_nl = sl_strchr(raw_map, '\n');
	while (last_nl != -1)
	{
		map->arr[line] = sl_substr(raw_map, 0, last_nl);
		tmp = raw_map;
		raw_map = sl_substr(raw_map, last_nl + 1, sl_strlen(raw_map, 0));
		free(tmp);
		last_nl = sl_strchr(raw_map, '\n');
		line++;
	}
	map->arr[line] = sl_strdup(raw_map);
	free(raw_map);
	validate_map_content(map);
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
	return (lines + 1);
}

void	read_map_file(int fd, char *raw_map)
{
	int		read_res;
	char	*read_buff;

	if (fd < 0)
		exit_sl(NULL, MAP_OPEN_ERR, MAP_OPEN_ERRC);
	read_res = 1;
	while (read_res > 0)
	{
		read_buff = sl_calloc(BUFFER_SIZE + 1);
		read_res = read(fd, read_buff, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(raw_map);
			free(read_buff);
			exit_sl(NULL, READ_ERR, READ_ERRC);
		}
		raw_map = sl_strjoin(raw_map, read_buff, 1);
	}
	close(fd);
	process_raw_map(init_map(count_lines(raw_map)), raw_map);
}

void	parse_map_input(char **args)
{
	int		size;
	char	*raw_map;

	size = 0;
	while (args[1][size] != '\0')
		size++;
	if (size <= 3 || args[1][size - 1] != 'r' || args[1][size - 2] != 'e'
		|| args[1][size - 3] != 'b' || args[1][size - 4] != '.')
		exit_sl(NULL, MAP_EXTENSION_ERR, MAP_EXTENSION_ERRC);
	raw_map = sl_strdup("");
	if (raw_map == NULL)
		exit_sl(NULL, MALLOC_ERR, MALLOC_ERRC);
	return (read_map_file(open(args[1], O_RDONLY), raw_map));
}
