/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:16:53 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/12 23:22:59 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_strcat(char *s, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	if (*s2)
	{
		s[i] = '/';
		i++;
	}
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
}

void	t_strjoin(char **s, char *s1)
{
	char	*tmp;

	tmp = malloc(ft_strlen(*s) + 1);
	ft_strcat(tmp, *s, "");
	free(*s);
	*s = malloc (ft_strlen(tmp) + ft_strlen(s1) + 2);
	ft_strcat(*s, tmp, s1);
	free(tmp);
}
