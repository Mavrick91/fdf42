/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:53:56 by maducham          #+#    #+#             */
/*   Updated: 2014/11/03 13:54:08 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	unsigned int	i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}
