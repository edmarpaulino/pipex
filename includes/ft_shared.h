/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:04:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/28 10:44:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHARED_H
# define FT_SHARED_H

# include "ft_utils.h"

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**system_path;
}				t_data;

int		ft_print_error_message(char *message);
char	**ft_get_system_path(char **envp);
int		ft_close_pipe(int *end);

#endif
