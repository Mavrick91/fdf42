/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:54:23 by maducham          #+#    #+#             */
/*   Updated: 2014/11/04 12:37:58 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned char	car;
	unsigned int	i;

	tmp = (unsigned char *)b;
	car = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		tmp[i] = car;
		i++;
	}
	return (b);
}
