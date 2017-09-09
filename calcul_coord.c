/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:44:50 by maducham          #+#    #+#             */
/*   Updated: 2016/05/17 16:26:40 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*calcul(t_tab *tab, t_window win)
{
	int		*res;

	res = malloc(sizeof(int) * 4);
	res[0] = (win.decalage * (win.i + 1) + win.next_floor) + win.start_x;
	res[1] = (win.decalage * (win.j + 1) + (tab->row[win.i] * win.h))
		+ win.start_y;
	res[2] = (res[0] + win.decalage);
	res[3] = (win.decalage * (win.j + 1) + (tab->row[win.i + 1] * win.h))
		+ win.start_y;
	return (res);
}

int			*calcul_next(int first, int second, t_window win)
{
	int		*res;

	res = malloc(sizeof(int) * 4);
	res[0] = (win.decalage * (win.j + 1) + win.next_floor) + win.start_x;
	res[1] = (win.decalage * (win.j + 1) + (first * win.h)) + win.start_y;
	res[2] = (res[0] + win.decalage);
	res[3] = ((res[1] - (first * win.h)) + win.decalage + (second * win.h));
	return (res);
}
