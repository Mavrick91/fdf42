/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:58:43 by maducham          #+#    #+#             */
/*   Updated: 2016/05/17 14:58:45 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 32

int					get_next_line(int const fd, char **line);

typedef struct		s_gnl
{
	int				fd;
	int				ret;
	int				i;
	char			*s;
	char			*tmp;
	char			**l;
	char			buf[BUFF_SIZE + 1];
	struct s_gnl	*next;
}					t_gnl;

#endif
