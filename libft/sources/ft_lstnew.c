/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:33:52 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:21:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new element. The variable
*	’content’ is initialized with the value of the parameter ’content’. The
*	variable ’next’ is initialized to NULL.
*
*	RETURN VALUES
*	The new element.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new)
	{
		new->content = content;
		new->next = 0;
	}
	return (new);
}
