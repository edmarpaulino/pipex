/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:04:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/01 09:39:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHARED_H
# define FT_SHARED_H

# include "ft_utils.h"

# define CMD_NF_ERR "pipex: command not found"
# define CMD_ARG_ERR "pipex: error in command's argurments"
# define WITHOUT_MESSAGE 0
# define WITH_MESSAGE 1

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**system_path;
}				t_data;

int		ft_print_error_message(char *message);
void	ft_clear_and_exit(t_data *data, char *message, char option);
char	**ft_get_system_path(char **envp);
int		ft_close_pipe(int *end);
char	*ft_get_cmd_path(char *cmd_name, char **system_path);

#endif
