/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:14:27 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/19 16:03:33 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == var[j])
		{
			if (!var[j + 1])
				return (ft_split(&env[i][j + 1], ':'));
			j++;
		}
		i++;
	}
	return (NULL);
}

void	ft_check_arg2(char **path, t_list *list, char **commande)
{
	int	i;

	i = 0;
	while (path[i])
	{
		t_strjoin(&path[i], *commande);
		if (!access(path[i], X_OK))
		{
			free(list->cmd);
			list->cmd = ft_strdup(path[i]);
			list->arg = commande;
			break ;
		}
		i++;
	}
	if (!path[i])
	{
		write(2, "zsh: command not found: ", 24);
		write(2, list->cmd, ft_strlen(list->cmd));
		write(2, "\n", 1);
	}
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_check_arg(char **env, t_list *elem)
{
	char	**commande;
	char	**path;

	path = get_path(env, "PATH=");
	commande = ft_split(elem->cmd, ' ');
	if (!*commande)
	{
		ft_free(path);
		elem->arg = commande;
		write(2, "zsh: command not found: ", 24);
		write(2, elem->cmd, ft_strlen(elem->cmd));
		write(2, "\n", 1);
		return ;
	}
	if (!access(*commande, X_OK))
	{
		free(elem->cmd);
		elem->cmd = ft_strdup(*commande);
		elem->arg = commande;
	}
	else
		ft_check_arg2(path, elem, commande);
	ft_free(path);
}
