/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:41:47 by maducham          #+#    #+#             */
/*   Updated: 2014/11/05 13:50:19 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*res;
	unsigned int	i;

	res = (char *)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
