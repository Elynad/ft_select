/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 02:27:51 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 06:47:57 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		print_list(t_lst *list, char sep)
{
	if (list && ft_strlen(list->name) > 0)
	{
		if (list->cursor == 1)
			ft_putstr_fd(tgetstr("us", NULL), 2);
		if (list->is_highlight == 1)
			ft_putstr_fd(tgetstr("so", NULL), 2);
		ft_putstr(list->name);
		ft_putstr_fd(tgetstr("ue", NULL), 2);
		ft_putstr_fd(tgetstr("se", NULL), 2);
		ft_putchar(sep);
	}
	if (list && list->next)
		print_list(list->next, sep);
}
