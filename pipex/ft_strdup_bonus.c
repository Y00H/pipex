/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:22:20 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/19 15:11:43 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = ft_strlen(s1);
	str = (char *) malloc(i * sizeof(char) + 1);
	if (str != NULL)
	{
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
