/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:16:34 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/07 03:20:56 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	*ft_pipe(int argc)
{
	int	i;
	int	*fd;

	argc -= 4;
	argc *= 2;
	fd = malloc(sizeof(int) * argc);
	if (!fd)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		pipe(&fd[i]);
		i += 2;
	}
	return (fd);
}

t_list	*ft_add_new(char *arg, char **env)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->cmd = ft_strdup(arg);
	new->arg = NULL;
	new->env = env;
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_list **head, t_list *new)
{
	t_list	*last;

	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_list	*store_arg(char **arg, char **env)
{
	t_list	*head;
	t_list	*list;
	int		i;

	i = 1;
	list = ft_add_new(arg[i], env);
	head = list;
	i++;
	while (arg[i])
	{
		list = ft_add_new(arg[i], env);
		ft_add_back(&head, list);
		i++;
	}
	return (head);
}
