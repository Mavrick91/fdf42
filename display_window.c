/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:55:25 by maducham          #+#    #+#             */
/*   Updated: 2016/05/26 13:37:17 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_map_next(t_window win)
{
	t_tab		*tmp_tab;
	int			first;
	int			second;

	win.i = 0;
	tmp_tab = win.tab;
	while (win.i < tmp_tab->width && win.i < win.win_width)
	{
		tmp_tab = win.tab;
		win.j = 0;
		while (win.j < win.height - 1 && win.j < win.win_height)
		{
			first = tmp_tab->row[win.i];
			tmp_tab = tmp_tab->next;
			second = tmp_tab->row[win.i];
			win.res = calcul_next(first, second, win);
			draw_segment(win);
			win.j++;
		}
		win.next_floor += win.var_floor;
		win.i++;
	}
	display_image_to_window(win);
	menu(win);
}

void		print_map(t_window win)
{
	t_tab		*tmp_tab;

	tmp_tab = win.tab;
	win.j = 0;
	while (win.j < win.height && win.j < win.win_height)
	{
		win.i = 0;
		while (win.i < win.max_width - 1 && win.i < win.win_width)
		{
			win.res = calcul(tmp_tab, win);
			draw_segment(win);
			win.i++;
		}
		win.next_floor += win.var_floor;
		win.j++;
		tmp_tab = tmp_tab->next;
	}
	win.next_floor = 0;
	print_map_next(win);
}

void		init(t_window *win, int height, int width)
{
	win->decalage = 30;
	win->height = height;
	win->h = -10;
	win->next_floor = 0;
	win->var_floor = 30;
	win->win_height = 1400;
	win->win_width = 1700;
	win->x = 0;
	win->y = 0;
	win->start_x = 10;
	win->start_y = 10;
	win->max_width = width;
	win->color = 0xAAAAAA;
}

void		display(t_tab *tab, t_info *info)
{
	t_window	win;

	init(&win, info->height, info->max_width);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr,
			win.win_width, win.win_height, "FDF");
	win.tab = tab;
	mlx_hook(win.win_ptr, 2, 3, key_hook, &win);
	mlx_expose_hook(win.win_ptr, expose_hook, &win);
	mlx_loop(win.mlx_ptr);
}
