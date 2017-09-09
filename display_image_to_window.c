/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:45:25 by maducham          #+#    #+#             */
/*   Updated: 2016/05/17 14:45:27 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		display_image_to_window(t_window win)
{
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.win, win.x, win.y);
}
