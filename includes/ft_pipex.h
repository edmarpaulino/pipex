/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:48:29 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/23 15:37:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <ft_utils.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_vars
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	**sys_path;
	char	**cmd1_args;
	char	**cmd2_args;
	char	**envp;
}				t_vars;

t_vars	*ft_init(t_vars *vars, char **argv, char **envp);
char	**ft_get_sys_path(char **envp);
void	ft_clear_memory(t_vars *vars);
int		ft_pipex(t_vars *vars);
char	*ft_get_cmd_path(char *cmd, char **sys_path);
int		ft_error_message(char *msg);

#endif
