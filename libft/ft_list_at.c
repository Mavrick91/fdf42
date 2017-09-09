/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:37:13 by maducham          #+#    #+#             */
/*   Updated: 2015/01/12 21:54:38 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*list;
	unsigned int	i;

	i = 0;
	list = begin_list;
	while (i < nbr)
	{
		if (!list)
			return (NULL);
		list = list->next;
		i++;
	}
	return (list);
}
