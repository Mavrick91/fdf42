/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:47:49 by maducham          #+#    #+#             */
/*   Updated: 2017/09/05 10:55:34 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	erreur_fdf(char *str)
{
	ft_putstr("error : ");
	ft_putstr(str);
	ft_putstr("\n");
	exit(-1);
}

void	max_width(char **str, t_info *info)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > info->max_width)
		info->max_width = i;
}

void	menu(t_window win)
{
	mlx_string_put(win.mlx_ptr, win.win_ptr, 0, 15, 0XFFFFFF, "Q = heuteur -");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 0, 40, 0XFFFFFF, "W = heuteur +");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 0, 65, 0XFFFFFF, "= = zoom +");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 0, 90, 0XFFFFFF, "/ = zoom -");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 0, 115, 0XFFFFFF, "arrow = moove");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 0, 140, 0XFFFFFF, "C = Color");
}
