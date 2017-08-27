/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:38:19 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/27 22:15:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		core(char **argv, int argc, int *highlight, int cursor_pos)
{
	char				str[4];
	char				*res;

	sel_print(&argv[1], cursor_pos, highlight);
	while (read(0, str, 3))
	{
		ft_putchar('\n');
		if ((res = tgetstr("cl", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		if (str[0] == 127)
			highlight[cursor_pos] = -1;
//		ft_putstr_fd(tgoto(res2, 1, 1), 1);
		sel_print(&argv[1], cursor_pos, highlight);
		ft_putendl(str);
		set_cursor_pos(str, &cursor_pos, argc);
		if (str[0] == 32)
		{
			if (highlight[cursor_pos] == 1)
				highlight[cursor_pos] = 0;
			else
				highlight[cursor_pos] = 1;
		}
		ft_strclr(str);
	}
}

void		set_cursor_pos(char *str, int *cursor_pos, int argc)
{
//	printf("[0] = %d | [1] = %d | [2] = %d\n", str[0], str[1], str[2]);
	if (str[0] == 27 && str[1] == 91 && str[2] == 'A' && *cursor_pos > 0)
		(*cursor_pos)--;
	else if (str[0] == 27 && str[1] == 91 && str[2] == 'B' && *cursor_pos < (argc - 2))
		(*cursor_pos)++;
}
