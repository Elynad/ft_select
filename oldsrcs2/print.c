/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 07:25:36 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 15:18:03 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		print_list(t_control *control, char sep)
{
	t_lst				*tmp;
	struct winsize		win;
	char				str[4];

	str[3] = '\0';
	ioctl(0, TIOCGWINSZ, &win);
	printf("HEIGHT = %d | WIDTH = %d\n", win.ws_row, win.ws_col);
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
			ft_putchar(sep);
			tmp = tmp->next;
		}
	}
}

/*
void		print_list(t_control *control, char sep)
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
			ft_putchar(sep);
			tmp = tmp->next;
		}
	}
}
*/

void		print_highlight(t_control *control)
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
}
