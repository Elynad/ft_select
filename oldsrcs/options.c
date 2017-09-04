/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 05:28:09 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/30 09:22:50 by mameyer          ###   ########.fr       */
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
		if (list->is_highlight == 1)
			list->is_highlight = 0;
		else
			list->is_highlight = 1;
	}
	else if (list && list->cursor == 0 && list->next)
		set_highlight(list->next);
}
