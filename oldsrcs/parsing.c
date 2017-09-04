/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 02:30:15 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 06:48:41 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		parsing(t_lst *list, char **arguments)
{
	int		a;

	a = 2;
	if (arguments[1])
	{
		list->name = ft_strdup(arguments[1]);
		list->cursor = 1;
		list->is_highlight = 0;
		list->prev = NULL;
	}
	while (arguments[a])
	{
		add_elem(list, arguments[a]);
		a++;
	}
}

void		add_elem(t_lst *list, char *str)
{
	if (list && list->next)
		add_elem(list->next, str);
	if (list && !(list->next))
	{
		if (!(list->next = malloc(sizeof(t_lst))))
			exit(EXIT_FAILURE);
		list->next->next = NULL;
		list->next->prev = list;
		list->next->name = ft_strdup(str);
		list->next->is_highlight = 0;
		list->next->cursor = 0;
	}
}
