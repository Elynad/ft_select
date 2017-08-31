/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:19:04 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 17:27:30 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		events(char *str)
{
//	printf("[0] = %d | [1] = %d | [2] = %d\n", str[0], str[1], str[2]);
	if (str[0] == 27 && str[1] == 91 && str[2] == 'A')
	{
		ft_debug("UP");
		glob->control = set_cursor_prev(glob->control);
	}
	else if (str[0] == 27 && str[1] == 91 && str[2] == 'B')
	{
		ft_debug("DOWN");
		glob->control = set_cursor_next(glob->control);
	}
	else if (str[0] == 32)
	{
		ft_debug("SPACE");
		glob->control = set_highlight(glob->control);
	}
	else if (str[0] == 127)
	{
		ft_debug("DEL");
		glob->control = delete_elem(glob->control);
	}
	else if (str[0] == 10)
	{
		ft_debug("RETURN");
		print_select(glob->control);
		glob->control = dll_clear_list(glob->control);
		exit(EXIT_SUCCESS);
	}
	else if (str[0] == 27)
	{
		ft_debug("ESC");
		glob->control = dll_clear_list(glob->control);
		exit(EXIT_SUCCESS);
	}
	ft_strclr(str);
}
