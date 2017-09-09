/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:49:37 by maducham          #+#    #+#             */
/*   Updated: 2016/05/17 14:49:39 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	list_push_back(t_tab **begin_tab, int *row, int width)
{
	t_tab	*tab;

	tab = *begin_tab;
	if (tab)
	{
		while (tab->next)
			tab = tab->next;
		tab->next = create_elem(row, width);
	}
	else
		*begin_tab = create_elem(row, width);
}
