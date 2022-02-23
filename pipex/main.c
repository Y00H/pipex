/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 01:15:57 by ajemraou          #+#    #+#             */
/*   Updated: 2022/02/21 23:59:50 by ajemraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_list	*list;

	if (argc == 5)
	{
		list = store_arg(argv);
		pipex(list, env);
	}
	return (0);
}
