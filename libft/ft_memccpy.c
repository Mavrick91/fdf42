/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:52:20 by maducham          #+#    #+#             */
/*   Updated: 2015/01/12 21:37:03 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*p;
	const char		*p2;

	i = 0;
	p = (char *)dest;
	p2 = (const char *)src;
	while (i < n && (i == 0 || p2[i - 1] != c))
	{
		p[i] = p2[i];
		i++;
	}
	if (i > 0 && p2[i - 1] == c)
		return (p + i);
	else
		return (NULL);
}
