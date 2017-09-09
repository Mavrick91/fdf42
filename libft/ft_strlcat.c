/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:26:50 by maducham          #+#    #+#             */
/*   Updated: 2014/11/05 13:04:28 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	int		n;
	size_t	i;
	int		a;

	i = 0;
	n = 0;
	while (dest[i] != '\0')
	{
		if (i == size)
			return (size + ft_strlen(src));
		i++;
	}
	a = i;
	while (src[n] != '\0' && i < (size - 1))
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	n = 0;
	while (src[n] != '\0')
		n++;
	dest[i] = '\0';
	return (a + n);
}
