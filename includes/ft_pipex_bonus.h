/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:44:54 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/30 10:35:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# define HERE_DOC 1
# define LIMITER 2
# define INFILE 1
# define CMD_NAME 0
# define CMD_NF "pipex: command not found: "

# include "ft_shared.h"

int		ft_pipex_bonus(t_data *data);
void	ft_here_doc_bonus(t_data *data);
int		ft_forker_bonus(int cmd_index, t_data *data);

#endif
