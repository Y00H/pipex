/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:04:03 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/19 16:02:20 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	t_list	*list;

	if (argc >= 5)
	{
		list = store_arg(argv, env);
		if (ft_strcmp(list->cmd, "here_doc") == 0 && !list->cmd[8])
			here_doc(list->next);
		else
			pipex(argc - 4, list);
	}
	return (0);
}
