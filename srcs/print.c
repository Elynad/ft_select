/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:11:59 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 18:16:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		print_list(t_control *control)
{
	t_lst		*tmp;

	if (dll_is_empty(control))
		return ;
	else
	{
		tmp = control->begin;
		while (tmp != NULL)
		{
			if (tmp->cursor == 1)
				ft_putstr_fd(tgetstr("us", NULL), 2);
			if (tmp->is_highlight == 1)
				ft_putstr_fd(tgetstr("so", NULL), 2);
			ft_putstr(tmp->name);
			ft_putstr_fd(tgetstr("ue", NULL), 2);
			ft_putstr_fd(tgetstr("se", NULL), 2);
			ft_putchar('\n');								// PRINT SEP
			tmp = tmp->next;
		}
	}
}

void		print_select(t_control *control)
{
	t_lst		*tmp;

	if (dll_is_empty(control))
		return ;
	else
	{
		tmp = control->begin;
		while (tmp != NULL)
		{
			if (tmp->is_highlight == 1)
			{
				ft_putstr(tmp->name);
				ft_putchar(' ');
			}
			tmp = tmp->next;
		}
	}
	ft_putchar('\n');
}
