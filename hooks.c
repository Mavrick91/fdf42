/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:54:20 by maducham          #+#    #+#             */
/*   Updated: 2016/05/26 14:58:28 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_window *win)
{
	win->win = mlx_new_image(win->mlx_ptr, win->win_width, win->win_height);
	win->data = mlx_get_data_addr(win->win, &win->bits,
		&win->lsize, &win->endian);
	print_map(*win);
	return (0);
}

void	key_hook_next_next(int keycode, t_window *win)
{
	if (keycode == 24)
	{
		win->var_floor += 2;
		win->decalage += 2;
	}
	if (keycode == 44)
	{
		if (win->var_floor - 2 > 0 && win->decalage - 2 > 0)
		{
			win->var_floor -= 2;
			win->decalage -= 2;
		}
	}
	if (keycode == 8)
	{
		win->color -= 10;
	}
	mlx_destroy_image(win->mlx_ptr, win->win);
	expose_hook(win);
}

void	key_hook_next(int keycode, t_window *win)
{
	if (keycode == 126)
	{
		win->start_y -= 20;
	}
	if (keycode == 125)
	{
		win->start_y += 20;
	}
	if (keycode == 124)
	{
		win->start_x += 20;
	}
	if (keycode == 123)
	{
		win->start_x -= 20;
	}
	key_hook_next_next(keycode, win);
}

int		key_hook(int keycode, t_window *win)
{
	if (!win)
	{
		ft_putstr("nope");
		exit(-1);
	}
	if (keycode == 12)
	{
		win->h--;
	}
	if (keycode == 13)
	{
		win->h++;
	}
	if (keycode == 53)
		exit(1);
	key_hook_next(keycode, win);
	return (0);
}
