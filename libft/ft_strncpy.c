/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:31:40 by maducham          #+#    #+#             */
/*   Updated: 2014/11/05 12:56:46 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, char const *src, size_t i)
{
	size_t	n;

	n = 0;
	while (src[n] != '\0' && n < i)
	{
		dest[n] = src[n];
		n++;
	}
	if (n < i)
	{
		while (n != i)
		{
			dest[n] = '\0';
			n++;
		}
	}
	return (dest);
}
