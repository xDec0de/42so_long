/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:22:24 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:27:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sl_strchr(char *s, char ch)
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
