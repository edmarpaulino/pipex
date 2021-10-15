/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:44:58 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:26:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Iterates the list ’lst’ and applies the function ’f’ to the content of each
*	element.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*elem;

	if (lst && (*f))
	{
		elem = lst;
		while (elem)
		{
			(*f)(elem->content);
			elem = elem->next;
		}
	}
}
