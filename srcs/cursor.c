/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:15:12 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 02:10:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		set_cursor_prev(t_lst *list)
{
	if (list && list->cursor == 1 && list->prev)
	{
		list->cursor = 0;
		list->prev->cursor = 1;
	}
	else if (list && list->cursor == 0 && list->next)
		set_cursor_prev(list->next);
}

void		set_cursor_next(t_lst *list)
{
	if (list && list->cursor == 1 && list->next)
	{
		list->cursor = 0;
		list->next->cursor = 1;
	}
	else if (list && list->cursor == 0 && list->next)
		set_cursor_next(list->next);
}

void		set_highlight(t_lst *list)
{
	if (list && list->cursor == 1)
	{
		if (list->highlight == 1)
			list->highlight = 0;
		else
			list->highlight = 1;
	}
	else if (list && list->next)
		set_highlight(list->next);
}

t_lst		*delete_elem(t_lst *list)
{
	t_lst		*tmp;

	if (list && list->cursor == 1)
	{
		if (list && !(list->next) && !(list->prev))
		{
			// EXCEPTION : The elem is the FIRST and the LAST
			ft_debug("EXCEPTION");
			free(list->name);
			free(list);
			exit(EXIT_SUCCESS);
		}
		else if (list && !(list->prev) && list->next)
		{
			// DELETE FIRST ELEM
			ft_debug("FIRST");
			list->next->cursor = 1;
			list->next->prev = NULL;
//			free(list->name);				// AVOID SOME LEAKS
						// NEED TO FREE LIST TOO
			tmp = list->next;
			*list = *list->next;			// WORKS BUT LEAKS
			free(list);
			return (tmp);					// WORKS BUT LEAKS
		}
		else if (list && list->next && list->prev)
		{
			// DELETE MIDDLE ELEM
			ft_debug("MIDDLE");
			list->prev->next = list->next;
			list->next->prev = list->prev;
			list->next->cursor = 1;
			free(list->name);
			free(list);
			return (list) ;
		}
		else if (list && !(list->next))
		{
			// DELETE LAST ELEM
			ft_debug("LAST");
			list->prev->next = NULL;
			list->prev->cursor = 1;
			free(list->name);
			free(list);
			return (list);
		}
	}
	else if (list->next)
		delete_elem(list->next);
	ft_debug("RETURN BULLSHIT");
	return (list);
}
