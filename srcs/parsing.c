/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:32:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 02:15:13 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_lst			*parsing(char **argv)
{
	t_lst		*list;
	int			a;

	a = 2;
	if (!(list = malloc(sizeof(t_lst))))
		exit(EXIT_FAILURE);
	list->next = NULL;
	list->prev = NULL;
	list->name = ft_strdup(argv[1]);
	list->highlight = 0;
	list->cursor = 0;
	while (argv[a])
	{
		set_elem(list, argv[a]);
		a++;
	}
	return (list);
}

void			set_elem(t_lst *begin, char *str)
{
	if (begin && begin->next)
		set_elem(begin->next, str);
	else if (begin && !(begin->next))
	{
		if (!(begin->next = malloc(sizeof(t_lst))))
			exit(EXIT_FAILURE);
		begin->next->next = NULL;
		begin->next->prev = begin;
		begin->next->name = ft_strdup(str);
		begin->next->highlight = 0;
		begin->next->cursor = 0;
	}
}
