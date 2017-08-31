/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:49:49 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 07:29:58 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		print_list(t_lst *begin, char sep)
{
	char		*res;

	if (begin->cursor == 1)
	{
		if ((res = tgetstr("us", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
	}
	if (begin->highlight == 1)
	{
		if ((res = tgetstr("so", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
	}
	if (begin)
	{
		ft_putstr(begin->name);
		if ((res = tgetstr("ue", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		if ((res = tgetstr("se", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
	}
	if (begin->next)
	{
		if ((res = tgetstr("ue", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		if ((res = tgetstr("se", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		ft_putchar(sep);
		print_list(begin->next, sep);
	}
}

void		sel_print(char **arguments, int cursor_pos, int *highlight)
{
	int			a;

	a = 0;
	while (arguments[a])
	{
		if (cursor_pos == a)
			print_str(arguments[a], 1, highlight[a]);
		else
			print_str(arguments[a], 0, highlight[a]);
		a++;
	}
}

void		print_str(char *argument, int cursor_pos, int highlight)
{
	char		*res;

	if (cursor_pos == 1)
	{
		if ((res = tgetstr("us", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
	}
	if (highlight == 1)
	{
		if ((res = tgetstr("so", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
	}
	ft_putendl(argument);
	if ((res = tgetstr("ue", NULL)) == NULL)
		exit(EXIT_FAILURE);
	ft_putstr_fd(res, 1);
	if ((res = tgetstr("se", NULL)) == NULL)
		exit(EXIT_FAILURE);
	ft_putstr_fd(res, 1);
}
