/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 21:55:07 by maducham          #+#    #+#             */
/*   Updated: 2015/01/12 21:55:12 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_tab		*create_elem(int *row, int width)
{
	t_tab		*tab;

	tab = (t_tab*)malloc(sizeof(t_tab));
	if (tab)
	{
		tab->row = row;
		tab->width = width;
		tab->next = NULL;
	}
	return (tab);
}
