/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:16:33 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:34:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The isdigit() function tests for a decimal digit character.  Regardless
*	of locale, this includes the following characters only:
*
*	``0''         ``1''         ``2''         ``3''         ``4''
*	``5''         ``6''         ``7''         ``8''         ``9''
*
*	The value of the argument must be representable as an unsigned char or
*	the value of EOF.
*
*	RETURN VALUES
*	The isdigit() function return zero if the character
*	tests false and return non-zero if the character tests true.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
