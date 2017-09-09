/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:49:44 by maducham          #+#    #+#             */
/*   Updated: 2014/11/03 15:50:06 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		u;
	char	*tmp;

	u = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	while (s1[u] != '\0')
	{
		tmp[u] = s1[u];
		u++;
	}
	while (s2[i] != '\0')
	{
		tmp[u] = s2[i];
		u++;
		i++;
	}
	tmp[u] = '\0';
	return (tmp);
}
