/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 07:19:46 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/30 11:02:24 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_control		*set_cursor_prev(t_control *control)
{
	t_lst		*tmp;

	tmp = NULL;
	if (!dll_is_empty(control))
		tmp = control->end;
	while (tmp != NULL)
	{
		if (tmp->cursor == 1)
		{
			tmp->cursor = 0;
			if (tmp->prev)
				tmp->prev->cursor = 1;
			else
				control->end->cursor = 1;
			return (control);
		}
		tmp = tmp->prev;
	}
	return (control);
}

t_control		*set_cursor_next(t_control *control)
{
	t_lst		*tmp;

	tmp = NULL;
	if (!dll_is_empty(control))
		tmp = control->begin;
	while (tmp != NULL)
	{
		if (tmp->cursor == 1)
		{
			tmp->cursor = 0;
			if (tmp->next)
				tmp->next->cursor = 1;
			else
				control->begin->cursor = 1;
			return (control);
		}
		tmp = tmp->next;
	}
	return (control);
}

t_control		*set_highlight(t_control *control)
{
	t_lst		*tmp;

	tmp = NULL;
	if (!dll_is_empty(control))
		tmp = control->begin;
	while (tmp != NULL)
	{
		if (tmp->cursor == 1)
		{
			if (tmp->is_highlight == 1)
				tmp->is_highlight = 0;
			else
				tmp->is_highlight = 1;
		}
		tmp = tmp->next;
	}
	control = set_cursor_next(control);
	return (control);
}

t_control		*delete_elem(t_control *control)
{
	t_lst		*tmp;

	tmp = NULL;
	if (!dll_is_empty(control))
		tmp = control->begin;
	while (tmp != NULL)
	{
		if (tmp->cursor == 1)
		{
			if (!tmp->next && tmp->prev)
			{
				tmp->prev->cursor = 1;
				control = dll_del_elem_end(control);
			}
			else if (!tmp->prev && tmp->next)
			{
				tmp->next->cursor = 1;
				control = dll_del_elem_front(control);
			}
			else if (!tmp->next && !tmp->prev)
			{
				free(tmp->name);
				free(tmp);
				exit(EXIT_SUCCESS);
			}
			else
			{
				if (tmp->next)
					tmp->next->cursor = 1;
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp->name);
				free(tmp);
				return (control);
			}
		}
		tmp = tmp->next;
	}
	return (control);
}
