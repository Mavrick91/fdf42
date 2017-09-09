/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:53:41 by maducham          #+#    #+#             */
/*   Updated: 2016/05/26 14:39:50 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_usage(void)
{
	ft_putstr("Usage : ./fdf <map>\n");
}

static size_t	is_correct_file(int fd)
{
	char	buf[1];

	if ((read(fd, buf, 1)) <= 0)
		return (1);
	return (0);
}

int open_file(char *av)
{
    int     fd;

    fd = open(av, O_RDONLY);
    if (fd < 0)
    {
        perror(av);
        return (0);
    }
	if (is_correct_file(fd))
		return 0;
	return fd;
}

int			main(int ac, char **av)
{
	t_info	*info;
	t_tab	*tab;
	int		fd;

	tab = NULL;
	if (ac == 2)
	{
		info = malloc(sizeof(t_info));
		if ((fd = open_file(av[1])) == 0)
        {
            ft_putstr("Error function open");
			return  (0);
        }
		info->max_width = 0;
		info->coord = parse_file(fd, info);
		tab = convert_coord(info, tab);
		display(tab, info);
	}
	else
		ft_usage();
	return (0);
}
