/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:49:41 by danimart          #+#    #+#             */
/*   Updated: 2022/05/06 17:09:08 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*lst_free(char **lst)
{
	if (*lst)
	{
		free(*lst);
		*lst = NULL;
	}
	return (NULL);
}

static char	*get_line(char **files, int fd)
{
	char	*tmp;
	char	*res;
	int		i;

	if (!files[fd])
		return (NULL);
	tmp = files[fd];
	i = ft_strchr(tmp, '\n');
	if (i == -1)
	{
		if (ft_strlen(tmp) <= 0)
			return (lst_free(files + fd));
		res = ft_strdup(tmp);
		lst_free(&files[fd]);
		return (res);
	}
	res = ft_substr(tmp, 0, i + 1);
	files[fd] = ft_substr(tmp, i + 1, (ft_strlen(tmp) - i));
	lst_free(&tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*files[FD_SIZE];
	int			read_res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!files[fd])
		files[fd] = ft_strdup("");
	read_res = 1;
	while (read_res > 0)
	{
		if (ft_strchr(files[fd], '\n') == -1)
		{
			read_res = read(fd, buf, BUFFER_SIZE);
			if (read_res == -1)
				return (lst_free(files + fd));
			buf[read_res] = '\0';
			files[fd] = ft_strjoin(files[fd], buf);
		}
		else
			return (get_line(files, fd));
	}
	return (get_line(files, fd));
}
