/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:19:04 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/01 03:08:43 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		events(char *str)
{
	if (str[0] == 27 && str[1] == 91 && str[2] == LEFT_ARROW)
		glob->control = set_cursor_prev(glob->control);
	else if (str[0] == 27 && str[1] == 91 && str[2] == UP_ARROW)
		glob->control = set_cursor_above(glob->control);
	else if (str[0] == 27 && str[1] == 91 && str[2] == RIGHT_ARROW)
		glob->control = set_cursor_next(glob->control);
	else if (str[0] == 27 && str[1] == 91 && str[2] == DOWN_ARROW)
		glob->control = set_cursor_below(glob->control);
	else if (str[0] == 32)
		glob->control = set_highlight(glob->control);
	else if (str[0] == 27 && str[1] == 91 && str[2] == 51)
		glob->control = delete_elem(glob->control);
	else if (str[0] == 10)
	{
		print_select(glob->control);
		glob->control = dll_clear_list(glob->control);
		exit(EXIT_SUCCESS);
	}
	else if (str[0] == 27)
	{
		glob->control = dll_clear_list(glob->control);
		exit(EXIT_SUCCESS);
	}
	ft_strclr(str);
}

/*
** printf("[0] = %d | [1] = %d | [2] = %d\n", str[0], str[1], str[2]);
*/
