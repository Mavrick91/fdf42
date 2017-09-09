/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:58:01 by maducham          #+#    #+#             */
/*   Updated: 2016/05/17 14:58:02 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnum(char *str)
{
	int		c;

	if (str[0] == '0')
		return (1);
	c = ft_atoi(str);
	if (c == 0)
		return (0);
	if (c < 2147000000 & c > -2147000000)
		return (1);
	return (0);
}
