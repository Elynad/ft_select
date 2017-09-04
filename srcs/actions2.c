/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 00:04:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/04 00:04:54 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_control			*set_cursor_below(t_control *control)
{
	t_lst		*tmp;
	t_lst		*save;
	int			a;

	tmp = NULL;
	save = NULL;
	a = 0;
	if (!dll_is_empty(control))
		tmp = control->begin;
	while (tmp != NULL)
	{
		if (tmp->cursor == 1)
			return (set_cursor_below_2(control, tmp));
		tmp = tmp->next;
	}
	return (control);
}

t_control			*set_cursor_above(t_control *control)
{
	t_lst		*tmp;
	t_lst		*save;
	int			a;

	tmp = NULL;
	save = NULL;
	a = 0;
	if (!dll_is_empty(control))
		tmp = control->end;
	while (tmp != NULL)
	{
		if (tmp->cursor == 1)
			return (set_cursor_above_2(control, tmp));
		tmp = tmp->prev;
	}
	return (control);
}

t_control			*set_cursor_above_2(t_control *control, t_lst *elem)
{
	int		a;
	t_lst	*save;

	a = 0;
	save = elem;
	while (elem != NULL && a < glob->words_per_line)
	{
		elem->cursor = 0;
		a++;
		if (elem->prev)
			elem = elem->prev;
		else
		{
			save->cursor = 1;
			return (control);
		}
		elem->cursor = 1;
	}
	return (control);
}

t_control			*set_cursor_below_2(t_control *control, t_lst *elem)
{
	int		a;
	t_lst	*save;

	a = 0;
	save = elem;
	while (elem != NULL && a < glob->words_per_line)
	{
		elem->cursor = 0;
		a++;
		if (elem->next)
			elem = elem->next;
		else
		{
			save->cursor = 1;
			return (control);
		}
		elem->cursor = 1;
	}
	return (control);
}
