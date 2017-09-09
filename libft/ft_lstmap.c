/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 21:14:27 by maducham          #+#    #+#             */
/*   Updated: 2015/01/12 22:06:38 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*neolst;
	t_list	*neobeg;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	neolst = (t_list *)malloc(sizeof(t_list));
	if (!neolst)
		return (NULL);
	neobeg = neolst;
	next = lst->next;
	*neolst = *(f(lst));
	lst = next;
	while (lst != NULL)
	{
		neolst->next = (t_list *)malloc(sizeof(t_list));
		neolst = neolst->next;
		if (!neolst)
			return (NULL);
		next = lst->next;
		*neolst = *(f(lst));
		lst = next;
	}
	return (neobeg);
}
