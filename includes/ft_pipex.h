/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:47:05 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/19 19:35:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	**sys_path;
	char	**param1;
	char	**param2;
}				t_data;

int		ft_pipex(t_data *data, char **envp);
char	**ft_get_path(char **envp);
char	*ft_get_cmd_path(char **path, char *cmd);
void	ft_clean_memory(t_data *data);

#endif
