/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:20:26 by maducham          #+#    #+#             */
/*   Updated: 2014/11/11 20:53:52 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*add_link(t_list *list, void *data)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = data;
		tmp->next = list;
	}
	return (tmp);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 2;
	if (ac == 1)
		return (NULL);
	list = ft_create_elem(av[1]);
	while (i < ac)
	{
		list = add_link(list, av[i]);
		i++;
	}
	return (list);
}
