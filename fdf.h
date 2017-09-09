/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 09:50:27 by maducham          #+#    #+#             */
/*   Updated: 2017/09/05 10:13:24 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

typedef struct		s_segment
{
	int				*rgb;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				xincr;
	int				yincr;
	int				erreur;
	int				i;
}					t_segment;

typedef struct		s_info
{
	int				height;
	int				max_width;
	char			**coord;
}					t_info;

typedef struct		s_tab
{
	int				*row;
	int				width;
	struct s_tab	*next;
}					t_tab;

typedef struct		s_window
{
	int				h;
	int				color;
	int				i;
	int				j;
	int				x;
	int				y;
	int				max_width;
	int				start_x;
	int				start_y;
	int				*res;
	int				bits;
	void			*win;
	int				lsize;
	int				endian;
	int				var_floor;
	int				next_floor;
	char			*data;
	int				height;
	int				win_height;
	int				win_width;
	int				decalage;
	void			*mlx_ptr;
	void			*win_ptr;
	t_tab			*tab;
}					t_window;

char				**parse_file(int fd, t_info *info);
void				display(t_tab *tab, t_info *info);
int					*calcul(t_tab *tab, t_window win);
int					*calcul_next(int first, int second, t_window win);
t_tab				*convert_coord(t_info *info, t_tab *tab);
void				draw_segment(t_window win);
int					expose_hook(t_window *win);
int					key_hook(int keycode, t_window *win);
void				print_map(t_window win);
void				list_push_back(t_tab **list, int *row, int width);
t_tab				*create_elem(int *row, int width);
void				display_image_to_window(t_window win);
void				erreur_fdf(char *str);
void				max_width(char **str, t_info *info);
void				menu(t_window win);

#endif
