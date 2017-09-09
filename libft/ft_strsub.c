/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:49:10 by maducham          #+#    #+#             */
/*   Updated: 2015/12/08 16:24:04 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (ft_strnew(len + 1));
	while (start <= len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	return (sub);
}
