/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:19:57 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/19 15:32:55 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct list_arg{
	char			*cmd;
	char			**arg;
	int				fds;
	struct list_arg	*next;
}t_list;

t_list	*store_arg(char **arg);
void	ft_check_arg(char **env, t_list *elem);
void	t_strjoin(char **s, char *s1);
void	pipex(t_list *list, char **env);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
