/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:17:20 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:17:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Outputs the string ’s’ to the given file descriptor.
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		write(fd, s, ft_strlen(s));
}
