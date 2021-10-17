/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:47:05 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/17 18:22:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# define BUFFER 256

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

char	**get_path(char **envp);
int		pipex(t_data *data, char **envp);

#endif
