/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:38:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:50:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The toupper() function converts a lower-case letter to the corresponding
*	upper-case letter.  The argument must be representable as an unsigned
*	char or the value of EOF.
*
*	RETURN VALUES
*	If the argument is a lower-case letter, the toupper() function returns
*	the corresponding upper-case letter if there is one; otherwise, the
*	argument is returned unchanged.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
