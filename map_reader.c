/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:19 by danimart          #+#    #+#             */
/*   Updated: 2025/03/05 16:28:03 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(int height)
{
	t_map	map;

	map.arr = malloc(height);
	if (map.arr == NULL)
		exit_sl(NULL, MALLOC_ERR, MALLOC_ERRC);
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
	exit_sl(&map, NULL, 0); // TODO: Fix double free
	//exit(0);
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

char	*ft_calloc(int amount)
{
	char	*res;

	res = malloc(amount * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (amount >= 0)
	{
		res[amount] = '\0';
		amount--;
	}
	return (res);
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
		read_buff = ft_calloc(BUFFER_SIZE + 1);
		read_res = read(fd, read_buff, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(raw_map);
			free(read_buff);
			exit_sl(NULL, READ_ERR, READ_ERRC);
		}
		raw_map = ft_strjoin(raw_map, read_buff, 1);
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
	raw_map = ft_strdup("");
	if (raw_map == NULL)
		exit_sl(NULL, MALLOC_ERR, MALLOC_ERRC);
	return (read_map_file(open(args[1], O_RDONLY), raw_map));
}
