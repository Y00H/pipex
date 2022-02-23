/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:07:46 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/21 23:58:33 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_commande(t_list *list, int *fd, char **env)
{
	list->fds = open(list->cmd, O_RDONLY);
	if (list->fds < 0)
	{
		perror(list->cmd);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	dup2(list->fds, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(list->fds);
	list = list->next;
	ft_check_arg(env, list);
	execve(list->cmd, list->arg, env);
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	second_commande(t_list *list, int *fd, char **env)
{
	t_list	*file;

	close(fd[1]);
	list = list->next;
	file = list->next;
	file->fds = open(file->cmd, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file->fds < 0)
	{
		perror(NULL);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	ft_check_arg(env, list);
	dup2(fd[0], 0);
	dup2(file->fds, 1);
	close(fd[0]);
	close(file->fds);
	execve(list->cmd, list->arg, env);
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	pipex(t_list *list, char **env)
{
	int	fd[2];

	pipe(fd);
	if (fork() == 0)
		first_commande(list, fd, env);
	if (fork() == 0)
		second_commande(list->next, fd, env);
	else
	{
		close(fd[0]);
		close(fd[1]);
		while (wait(NULL) != -1)
			;
	}
}
