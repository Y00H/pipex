/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:00:36 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/13 00:26:15 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_strcpy_cat(char *s1, char *s2, char *s3)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (s3[j])
	{
		s1[i + j] = s3[j];
		j++;
	}
	s1[i + j] = '\0';
}

void	f_strjoin(char **s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (!*s1)
		*s1 = ft_strdup(s2);
	else
	{
		tmp = ft_strdup(*s1);
		free(*s1);
		*s1 = malloc(ft_strlen(tmp) + ft_strlen(s2) + 1);
		ft_strcpy_cat(*s1, tmp, s2);
		free(tmp);
	}
}
