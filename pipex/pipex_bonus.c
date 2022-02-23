/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:32:46 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/22 00:04:54 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_creat_new_child(int nb, int *fd, int size, t_list *list)
{
	if (fork() == 0)
	{
		if (list->in == -1 || list->out == -1)
			exit(EXIT_FAILURE);
		multiple_pipe(fd, size, list->in, list->out);
		ft_check_arg(list->env, list);
		execve(list->cmd, list->arg, list->env);
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	else if (nb != 0)
	{
		nb--;
		ft_creat_new_child(nb, fd, size, list->next);
	}
	else
	{
		multiple_pipe(fd, size, 0, 1);
		while (wait(NULL) != -1)
			;
	}
}

void	open_file(t_list *file)
{
	t_list	*first;

	first = file->next;
	first->in = open(file->cmd, O_RDWR);
	if (first->in == -1)
		perror(file->cmd);
}

void	store_fd(t_list *list, int *fd)
{
	t_list	*first;
	t_list	*second;
	int		i;

	first = list;
	second = first->next;
	i = 0;
	while (second->next)
	{
		if (i == 0)
			open_file(first);
		first = first->next;
		second = first->next;
		if (!second->next)
			break ;
		second->in = fd[i];
		i++;
		first->out = fd[i];
		i++;
	}
	first->out = open(second->cmd, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (first->out == -1)
		perror(second->cmd);
}

void	pipex(int argc, t_list *list)
{
	t_list	*head;
	int		*fd;

	head = list;
	fd = ft_pipe(argc + 4);
	store_fd(list, fd);
	list = head;
	ft_creat_new_child(argc, fd, argc * 2, list->next);
	free(fd);
}
