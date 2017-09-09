/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:01:39 by maducham          #+#    #+#             */
/*   Updated: 2015/04/21 22:29:35 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	list = NULL;
	while (*alst && del)
	{
		list = *alst;
		*alst = (*alst)->next;
		del((list)->content, (list)->content_size);
		free(list);
	}
}
