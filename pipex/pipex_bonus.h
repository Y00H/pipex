/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:34:02 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/19 15:27:06 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct list_arg{
	int				in;
	int				out;
	char			*cmd;
	char			**arg;
	char			**env;
	struct list_arg	*next;
}t_list;

t_list	*store_arg(char **arg, char **env);
void	ft_strjoin_bonus(char **s, char *s1);
void	ft_check_arg(char **env, t_list *args);
int		*ft_pipe(int argc);
void	multiple_pipe(int *fd, int size, int in, int out);
void	pipex(int argc, t_list *list);
void	here_doc(t_list *list);
char	*get_next_line(int fd);
void	f_strjoin(char **s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
