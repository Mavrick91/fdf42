/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:28:09 by maducham          #+#    #+#             */
/*   Updated: 2015/12/06 17:46:09 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtoupper(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		if (!((str[i] >= 'A') && (str[i] <= 'Z')))
			str[i] -= 32;
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}
