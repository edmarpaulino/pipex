/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:02:51 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:07:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The atoi() function converts the initial portion of the string pointed
*	to by str to int representation.
*/

int	ft_atoi(const char *str)
{
	signed char		sign;
	unsigned int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
		nbr = (nbr * 10) + (*(str++) - '0');
	return (nbr * sign);
}
