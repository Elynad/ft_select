/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:37:18 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/03 23:37:20 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_control		*delete_manager(t_control *control, t_lst *elem)
{
	if (!elem->next && elem->prev)
		return (del_last_elem(control, elem));
	else if (!elem->prev && elem->next)
		return (del_first_elem(control, elem));
	else if (!elem->next && !elem->prev)
		del_only_elem(elem);
	return (control);
}

t_control		*del_last_elem(t_control *control, t_lst *elem)
{
	elem->prev->cursor = 1;
	control = dll_del_elem_end(control);
	return (control);
}

t_control		*del_first_elem(t_control *control, t_lst *elem)
{
	elem->next->cursor = 1;
	control = dll_del_elem_front(control);
	return (control);
}

void			del_only_elem(t_lst *elem)
{
	free(elem->name);
	free(elem);
	if (tcsetattr(0, TCSANOW, &glob->default_term) == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

t_control		*del_regular_elem(t_control *control, t_lst *elem)
{
	if (elem->next)
		elem->next->cursor = 1;
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	free(elem->name);
	free(elem);
	return (control);
}
