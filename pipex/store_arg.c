/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:10:28 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/13 00:30:37 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ft_add_new(char *arg)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->cmd = ft_strdup(arg);
	new->arg = NULL;
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

t_list	*store_arg(char **arg)
{
	t_list	*head;
	t_list	*list;
	int		i;

	i = 1;
	list = ft_add_new(arg[i]);
	head = list;
	i++;
	while (arg[i])
	{
		list = ft_add_new(arg[i]);
		ft_add_back(&head, list);
		i++;
	}
	return (head);
}
