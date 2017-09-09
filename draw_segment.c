/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:46:24 by maducham          #+#    #+#             */
/*   Updated: 2016/05/26 14:05:03 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_segment(t_segment *segment, t_window win)
{
	segment->rgb = (int*)malloc(sizeof(int) * 4);
	segment->rgb[0] = win.color;
	segment->x1 = win.res[0];
	segment->y1 = win.res[1];
	segment->x2 = win.res[2];
	segment->y2 = win.res[3];
	segment->dx = abs(segment->x2 - segment->x1);
	segment->dy = abs(segment->y2 - segment->y1);
}

void		draw_segment_next(t_segment *seg)
{
	if (seg->x1 < seg->x2)
		seg->xincr = 1;
	else
		seg->xincr = -1;
	if (seg->y1 < seg->y2)
		seg->yincr = 1;
	else
		seg->yincr = -1;
	seg->x = seg->x1;
	seg->y = seg->y1;
}

void		draw_segment_next_3(t_segment *seg, t_window win)
{
	seg->erreur = seg->dy / 2;
	seg->i = 0;
	while (seg->i < seg->dy)
	{
		seg->y += seg->yincr;
		seg->erreur += seg->dx;
		if (seg->erreur > seg->dy)
		{
			seg->erreur -= seg->dy;
			seg->x += seg->xincr;
		}
		if (seg->x < win.win_width - 2 && seg->y < win.win_height - 2
				&& seg->x > 2 && seg->y > 2)
		{
			ft_memcpy(win.data + seg->y * win.lsize + seg->x * win.bits / 8
				, seg->rgb, win.bits / 8);
		}
		seg->i++;
	}
	if (seg->x < win.win_width - 2 && seg->y < win.win_height - 2
			&& seg->x > 2 && seg->y > 2)
	{
		ft_memcpy(win.data + seg->y * win.lsize + seg->x * win.bits / 8,
				seg->rgb, win.bits / 8);
	}
}

void		draw_segment_next_2(t_segment *seg, t_window win)
{
	if (seg->dx > seg->dy)
	{
		seg->erreur = seg->dx / 2;
		seg->i = 0;
		while (seg->i < seg->dx)
		{
			seg->x += seg->xincr;
			seg->erreur += seg->dy;
			if (seg->erreur > seg->dx)
			{
				seg->erreur -= seg->dx;
				seg->y += seg->yincr;
			}
			if (seg->x < win.win_width - 5 && seg->y < win.win_height - 5
				&& seg->x > 5 && seg->y > 5)
			{
				ft_memcpy(win.data + seg->y * win.lsize + seg->x * win.bits / 8,
					seg->rgb, win.bits / 8);
			}
			seg->i++;
		}
	}
	else
		draw_segment_next_3(seg, win);
}

void		draw_segment(t_window win)
{
	t_segment	segment;

	init_segment(&segment, win);
	draw_segment_next(&segment);
	draw_segment_next_2(&segment, win);
}
