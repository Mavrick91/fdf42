/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:51:30 by maducham          #+#    #+#             */
/*   Updated: 2014/11/04 16:06:30 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*desti;
	unsigned char	*srce;
	unsigned int	i;
	unsigned char	*tmp;

	desti = (unsigned char *)dest;
	srce = (unsigned char *)src;
	i = 0;
	tmp = (unsigned char *)malloc(sizeof(unsigned char) * n);
	while (n > i)
	{
		tmp[i] = srce[i];
		i++;
	}
	i = 0;
	while (n > i)
	{
		desti[i] = tmp[i];
		i++;
	}
	return (dest);
}
