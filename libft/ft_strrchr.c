/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:21:30 by maducham          #+#    #+#             */
/*   Updated: 2014/11/04 14:26:21 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (s[i] != c && i >= 0)
		i--;
	if (s[i] == c)
		return ((char*)s + i);
	else
		return (0);
}
