/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 02:49:32 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 09:04:14 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_lst		*delete_manager(t_lst *list)
{
	if (list && !(list->prev))
	{
		ft_debug("A");
		return (delete_first_elem(list));
	}
	else if (list && list->prev && list->next)
	{
		ft_debug("B");
		return (delete_elem(list));
	}
	else if (list && list->next && !(list->prev))
	{
		ft_debug("C");
		return (delete_last_elem(list, list));
	}
	else
	{
		ft_debug("D");
		return (list);
	}
}

t_lst		*delete_first_elem(t_lst *list)
{
	t_lst		*tmp;

	ft_debug("0");
	tmp = NULL;
	if (list->next)
	{
		ft_debug("1");
		list->next->cursor = 1;
		ft_debug("2");
		tmp = list->next;
		ft_debug("3");
	}
	ft_debug("4");
	printf("%p\n", list->name);
	free(list->name);
	ft_debug("5");
	free(list);
	ft_debug("6");
	return (tmp);
}

t_lst		*delete_elem(t_lst *list)
{
	if (list && list->cursor == 1)
	{
		list->next->cursor = 1;
		list->prev->next = list->next;
		list->next->prev = list->prev;
		free(list->name);
		free(list);
	}
	else if (list && list->next)
		delete_elem(list->next);
	return (list);
}

t_lst		*delete_last_elem(t_lst *list, t_lst *begin)
{
	if (list && list->next)
		delete_last_elem(list->next, begin);
	else if (list && !(list->next))
	{
		if (list->prev)
		{
			list->prev->cursor = 1;
			list->prev->next = NULL;
		}
		free(list->name);
		free(list);
	}
	return (begin);
}
