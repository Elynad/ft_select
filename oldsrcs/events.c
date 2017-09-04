/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 05:17:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 07:39:18 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		events(char *str, t_lst *list)
{
//	printf("[0] = %d | [1] = %d | [2] = %d\n", str[0], str[1], str[2]);
	if (str[0] == 27 && str[1] == 91)
	{
		if (str[2] == 'A')
		{
			ft_debug("UP");										// DEBUG
			set_cursor_prev(list);
		}
		else if (str[2] == 'B')
		{
			ft_debug("DOWN");									// DEBUG
			set_cursor_next(list);
		}
	}
	else if (str[0] == 32)
	{
		ft_debug("SPACE");										// DEBUG
		set_highlight(list);
	}
	else if (str[0] == 127)
	{
		ft_debug("DEL");										// DEBUG
		delete_manager(list);
		/*		if (list && list->prev && list->next)
		{
			ft_debug("CASE 0");
			list = delete_elem(list);
		}
		else if (list && !(list->prev) && !(list->next))
		{
			ft_debug("CASE 1");
		}
		else if (list && !(list->prev))
		{
			ft_debug("CASE 2");
			list = delete_first_elem(list);
		}
		else if (list && !(list->next))
		{
			ft_debug("CASE 3");
			list = delete_last_elem(list, list);
		}*/
	}
	else if (str[0] == 27)
	{
		ft_debug("ESC");										// DEBUG
		free_list(list);
		exit(EXIT_SUCCESS);
	}
}
