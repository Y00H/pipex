/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:57:04 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/13 00:26:12 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int		x;
	char	*str;
	char	buff[2];

	str = NULL;
	if (read(fd, buff, 0) < 0)
		return (NULL);
	x = 1;
	while (x)
	{
		x = read(fd, buff, 1);
		if (x == 0)
			return (str);
		buff[x] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else if (!ft_check(buff))
			f_strjoin(&str, buff);
		if (ft_check(buff))
			return (str);
	}
	return (NULL);
}
