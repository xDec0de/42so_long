/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:08:07 by danimart          #+#    #+#             */
/*   Updated: 2022/05/07 14:28:15 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str, int ignore_new_line)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str && str[i] != '\0')
	{
		if ((ignore_new_line == 1 && str[i] != '\n') || ignore_new_line != 1)
			res++;
		i++;
	}
	return (res);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((ft_strlen(s, 0) + 1) * sizeof(char));
	if (!s || !str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strchr(char *s, char ch)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc((ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1) \
		* sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i + j] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s, 0))
		return (ft_strdup(""));
	j = ft_strlen(&s[start], 0);
	if (j < len)
		len = j;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
