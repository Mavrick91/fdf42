/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:50:50 by maducham          #+#    #+#             */
/*   Updated: 2015/12/09 14:57:56 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	char	*tmp;

	tmp = NULL;
	list = *begin_list;
	while (list->next)
	{
		if (cmp(list->data, (list->next)->data) > 0)
		{
			tmp = list->data;
			list->data = (list->next)->data;
			list->next->data = tmp;
			list = *begin_list;
		}
		list = list->next;
	}
}
