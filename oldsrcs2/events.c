/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 07:08:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/30 11:02:16 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		events(char *str, t_control *control)
{
//	printf("[0] = %d | [1] = %d | [2] = %d\n", str[0], str[1], str[2]);
	if (str[0] == 27 && str[1] == 91)
	{
		if (str[2] == 'A')
		{
			ft_debug("UP");
			control = set_cursor_prev(control);
		}
		else if (str[2] == 'B')
		{
			ft_debug("DOWN");
			control = set_cursor_next(control);
		}
	}
	else if (str[0] == 32)
	{
		ft_debug("SPACE");
		control = set_highlight(control);
	}
	else if (str[0] == 127)
	{
		ft_debug("DEL");
		control = delete_elem(control);
	}
	else if (str[0] == 10)
	{
		ft_debug("SPACE");
		print_highlight(control);
		control = dll_clear_list(control);
		exit(EXIT_SUCCESS);
	}
	else if (str[0] == 27)
	{
		ft_debug("ESC");
		control = dll_clear_list(control);
		exit(EXIT_SUCCESS);
	}
	ft_strclr(str);
}
