/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:09:52 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:08:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The calloc() function allocate memory.  The allocated memory is aligned
*	such that it can be used for any data type, including AltiVec- and
*	SSE-related types.
*
*	The calloc() function contiguously allocates enough space for count
*	objects that are size bytes of memory each and returns a pointer to the
*	allocated memory.  The allocated memory is filled with bytes of value
*	zero.
*
*	RETURN VALUES
*	If successful, calloc() functions return a pointer to allocated
*	memory.  If there is an error, they return a NULL pointer and set errno
*	to ENOMEM.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
