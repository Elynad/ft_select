/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <mameyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:11:59 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/03 10:55:57 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		print_list(t_control *control)
{
	int			a;
	int			pos;
	t_lst		*tmp;

	print_calc(control, 0);
	if (will_it_fit() == -1)
		return ;
	tmp = control->begin;
	print_interface();
	while (tmp != NULL)
	{
		a = 0;
		pos = 0;
		while (a < glob->words_per_line && tmp != NULL)
		{
			pos += (ft_strlen(tmp->name) + (glob->spaces * (a - 1)));
			print_single_elem(tmp);
			print_spaces(tmp);
			tmp = tmp->next;
			a++;
		}
		ft_putchar('\n');
	}
	print_interface();
}

void		print_spaces(t_lst *elem)
{
	int			a;
	int			next_col;
	int			spaces;

	a = 0;
	next_col = glob->longest_word + glob->spaces;
	spaces = next_col - ft_strlen(elem->name);
	while (a < spaces)
	{
		ft_putchar(' ');
		a++;
	}
}

void		print_single_elem(t_lst *elem)
{
	if (elem)
	{
		if (elem->cursor == 1)
			ft_putstr_fd(tgetstr("us", NULL), 2);
		if (elem->is_highlight == 1)
			ft_putstr_fd(tgetstr("so", NULL), 2);
		ft_putstr(elem->name);
		ft_putstr_fd(tgetstr("ue", NULL), 2);
		ft_putstr_fd(tgetstr("se", NULL), 2);
	}
}

void		print_select(t_control *control)
{
	t_lst		*tmp;
	int			a;

	a = 0;
	if (dll_is_empty(control))
		return ;
	else
	{
		tmp = control->begin;
		while (tmp != NULL)
		{
			if (tmp->is_highlight == 1)
			{
				a++;
				ft_putstr(tmp->name);
				ft_putchar(' ');
			}
			tmp = tmp->next;
		}
	}
	if (a != 0)
		ft_putchar('\n');
}
