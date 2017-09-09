/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:45:45 by maducham          #+#    #+#             */
/*   Updated: 2014/11/03 15:45:58 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
