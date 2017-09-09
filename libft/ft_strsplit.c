/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:51:48 by maducham          #+#    #+#             */
/*   Updated: 2016/05/17 14:57:47 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nbword(char const *s, char c)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\t')
		{
			while (s[i] != '\0' && s[i] != c && s[i] != '\t')
				i++;
			res++;
		}
		if (s[i] == c || s[i] == '\t')
			i++;
	}
	return (res);
}

static int	ft_len_letter(char const *str, char character, int z)
{
	int		nb_letter;
	int		i;

	i = 0;
	nb_letter = 0;
	while (str[i] != '\0')
	{
		if (str[z] == character)
		{
			while (str[z] == character)
			{
				z++;
				i++;
			}
		}
		while (str[z] != character && str[z] != '\0')
		{
			nb_letter++;
			z++;
			i++;
		}
	}
	return (nb_letter);
}

void		function(char *c)
{
	if (*c == '@')
		*c = ' ';
	else if (*c == ' ')
		*c = '@';
}

static char	**ft_init_tmp(char **tmp, char const *str, char character)
{
	int		i;
	int		z;
	int		u;

	i = 0;
	z = 0;
	u = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != character && str[i] != '\t' && str[i] != '\"')
		{
			while (str[i] != character && str[i] != '\0' && str[i] != '\n'
				&& str[i] != '\t' && str[i] != '\"')
				tmp[u][z++] = str[i++];
			tmp[u++][z] = '\0';
			z = 0;
		}
		if (str[i] == '\"')
			function(&character);
		if (str[i] == character || str[i] == '\t' || str[i] == '\"')
			i++;
	}
	tmp[u] = NULL;
	return (tmp);
}

char		**ft_strsplit(char const *str, char character)
{
	char	**tmp;
	int		nb_words;
	int		index;
	int		offset_str;

	offset_str = 0;
	index = 0;
	if (!str)
		return (NULL);
	nb_words = ft_nbword(str, character);
	tmp = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!tmp)
		return (NULL);
	while (nb_words > index)
	{
		tmp[index] = (char *)malloc(
				sizeof(char) * (ft_len_letter(str, character, offset_str) + 1));
		index++;
	}
	return (ft_init_tmp(tmp, str, character));
}
