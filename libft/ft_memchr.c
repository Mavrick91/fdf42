/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:43:34 by maducham          #+#    #+#             */
/*   Updated: 2015/01/12 21:38:33 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = (char *)s;
	if (s && n > 0)
	{
		while (i < n)
		{
			if (p[i] == (char)c)
			{
				return ((void *)(p + i));
			}
			i++;
		}
	}
	return (NULL);
}
