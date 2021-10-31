/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:44:54 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/31 12:27:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# define HERE_DOC 1
# define LIMITER 2
# define INFILE 1
# define CMD_NAME 0
# define CMD_NF "pipex: command not found: "
# define WITHOUT_MESSAGE 0
# define WITH_MESSAGE 1

# include "ft_shared.h"

int		ft_init_bonus(t_data *data);
void	ft_clear_and_exit_bonus(t_data *data, char *message, char option);
void	ft_here_doc_bonus(t_data *data);
int		ft_pipex_bonus(int cmd_index, t_data *data);

#endif
