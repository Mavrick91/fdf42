/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:57:12 by maducham          #+#    #+#             */
/*   Updated: 2016/05/17 15:24:25 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**parse_file(int fd, t_info *info)
{
	char	**parser;
	char	*str;
	int		i;

	i = 0;
	parser = (char**)malloc(sizeof(char*) * 10000);
	while (get_next_line(fd, &str))
	{
		if (str[0] != '\n')
		{
			parser[i] = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
			parser[i] = str;
			i++;
		}
	}
	info->height = i;
	return (parser);
}

int			*coord_to_int(char **str, t_info *info)
{
	int		*tab;
	int		i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * 1000);
	while (str[i])
	{
		if (ft_isnum(str[i]))
			tab[i] = ft_atoi(str[i]);
		else
			erreur_fdf("Bad parsing");
		i++;
	}
	if (i > info->max_width)
		info->max_width = i;
	return (tab);
}

int			calcul_width(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			*remplissage(int *row, t_info *info, int width)
{
	int		*row_tmp;
	int		i;

	row_tmp = (int*)malloc(sizeof(int) * info->max_width);
	i = 0;
	while (i < width)
	{
		row_tmp[i] = row[i];
		i++;
	}
	while (i < info->max_width)
	{
		row_tmp[i] = 0;
		i++;
	}
	return (row_tmp);
}

t_tab		*convert_coord(t_info *info, t_tab *tab)
{
	int		i;
	int		*row;
	int		width;
	char	**split;

	i = 0;
	if (info->height == 0)
		erreur_fdf("file empty");
	while (i < info->height)
	{
		split = ft_strsplit(info->coord[i], ' ');
		max_width(split, info);
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		split = ft_strsplit(info->coord[i], ' ');
		width = calcul_width(split);
		row = coord_to_int(split, info);
		row = remplissage(row, info, width);
		list_push_back(&tab, row, width);
		i++;
	}
	return (tab);
}
