/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:29:59 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/22 00:03:31 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	read_frome_usr(t_list *list, int *fd)
{
	char	*s;

	ft_putstr_fd("pipe heredoc> ", 1);
	s = get_next_line(0);
	while (s && ft_strcmp(list->cmd, s))
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		ft_putendl_fd(s, fd[1]);
		free(s);
		s = NULL;
		s = get_next_line(0);
	}
	free(s);
}

void	exec_last_commande(t_list *list, int *fd)
{
	t_list	*file;

	file = list->next;
	list->out = open(file->cmd, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (list->out < 0)
		perror(NULL);
	multiple_pipe(fd, 4, fd[2], list->out);
	ft_check_arg(list->env, list);
	execve(list->cmd, list->arg, list->env);
	perror(NULL);
	close(EXIT_FAILURE);
}

void	here_doc(t_list *list)
{
	int	*fd;

	fd = ft_pipe(6);
	read_frome_usr(list, fd);
	list = list->next;
	if (fork() == 0)
	{
		multiple_pipe(fd, 4, fd[0], fd[3]);
		ft_check_arg(list->env, list);
		execve(list->cmd, list->arg, list->env);
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	if (fork() == 0)
		exec_last_commande(list->next, fd);
	else
	{
		multiple_pipe(fd, 4, 0, 1);
		while (wait(NULL) != -1)
			;
		free(fd);
	}
}
