/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:44:42 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:26:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Deletes and frees the given element and every successor of that element,
*	using the function ’del’ and free(3). Finally, the pointer to the list must
*	be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (lst && (*del))
	{
		while (*lst)
		{
			elem = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(elem, (*del));
		}
		*lst = NULL;
	}
}
