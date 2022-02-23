/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:33:26 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/19 15:07:59 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_replace(char const *str, char c)
{
	int		i;
	char	*srr;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	srr = (char *) malloc(sizeof(char) * (i + 1));
	if (srr != NULL)
	{
		i = 0;
		while (str[i] && str[i] != c)
		{
			srr[i] = str[i];
			i++;
		}
		srr[i] = '\0';
		return (srr);
	}
	return (NULL);
}

int	ft_sepa(char const *str, char c)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			x++;
		else if (str[i] != c && i == 0)
			x++;
		i++;
	}
	return (x + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**matr;
	int		count;
	int		i;
	int		x;

	if (!s)
		return (NULL);
	count = ft_sepa(s, c);
	matr = (char **) malloc(sizeof(char *) * count);
	if (matr == NULL)
		return (NULL);
	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if ((i == 0) || (count > x + 1 && s[i - 1] == c && s[i]))
			matr[x++] = ft_replace(&s[i], c);
		if (s[i] != '\0')
			i++;
	}
	matr[x] = 0;
	return (matr);
}
