/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:38:19 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 02:16:20 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		core(t_lst *list)
{
	char			str[4];
	char			*res;

	print_list(list, '\n');
	while (read(0, str, 3))
	{
		if ((res = tgetstr("cl", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		events(str, list);
		print_list(list, '\n');
		ft_strclr(str);
	}
}

void		events(char *str, t_lst *list)
{
//	printf("[0] = %d | [1] = %d | [2] = %d\n", str[0], str[1], str[2]);
	if (str[0] == 27 && str[1] == 91 && str[2] == 'A')
	{
		ft_debug("UP");
		set_cursor_prev(list);
	}
	else if (str[0] == 27 && str[1] == 91 && str[2] == 'B')
	{
		ft_debug("DOWN");
		set_cursor_next(list);
	}
	else if (str[0] == 32)
	{
		ft_debug("SPACE");
		set_highlight(list);
	}
	else if (str[0] == 127)
	{
		ft_debug("DEL");
//		free(list->next);
		list = delete_elem(list);
		ft_debug("BACK TO EVENT, LIST->NAME VALUE");
		ft_debug(list->name);
	}
	else if (str[0] == 27)
	{
		free_list(list);
		exit(EXIT_SUCCESS);
	}
}
