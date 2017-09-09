/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:50:49 by maducham          #+#    #+#             */
/*   Updated: 2014/11/05 13:52:23 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*res;

	if (!s || s[0] == '\0')
		return (ft_strnew(1));
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > start)
		end--;
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
