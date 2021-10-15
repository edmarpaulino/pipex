/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:42:00 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/15 15:06:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**my_path;

	if (!*envp)
		return (1);
	i = -1;
	while (++i < argc)
		ft_putendl_fd(argv[i], 1);
	my_path = get_path(envp);
	if (!my_path)
		return (1);
	i = -1;
	while (my_path[++i])
		ft_putendl_fd(my_path[i], 1);
	ft_clear_split(my_path);
	return (0);
}
