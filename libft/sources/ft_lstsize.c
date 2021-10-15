/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:37:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:22:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Counts the number of elements in a list.
*
*	RETURN VALUES
*	Length of the list.
*/

int	ft_lstsize(t_list *lst)
{
	t_list	*elem;
	int		size;

	elem = lst;
	size = 0;
	while (elem)
	{
		elem = elem->next;
		++size;
	}
	return (size);
}
