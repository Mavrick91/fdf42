/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:15:00 by maducham          #+#    #+#             */
/*   Updated: 2014/11/11 20:52:54 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*list;

	list = begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		return (list);
	}
	return (NULL);
}
