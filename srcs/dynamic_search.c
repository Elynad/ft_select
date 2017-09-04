/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 03:09:20 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/04 03:09:22 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_control			*research(char *str, t_control *control)
{
	t_lst	*tmp;

	tmp = glob->control->begin;
	add_char(str[0]);
	ft_putstr("Search = ");
	ft_putendl(glob->research);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->name, glob->research,
			ft_strlen(glob->research)) == 0)
		{
			control = remove_cursor(control);
			tmp->cursor = 1;
		}
		tmp = tmp->next;
	}
	return (control);
}

void				add_char(char c)
{
	int			a;

	a = 0;
	while (a < 50 && glob->research[a] >= 33 && glob->research[a] < 127)
		a++;
	if (a < 50 && c != 127 && a >= 0)
		glob->research[a] = c;
	else if (a < 50 && c == 127 && a >= 0)
		glob->research[a - 1] = 0;
}

void				init_search_char(void)
{
	int			a;

	a = 0;
	while (a < 50)
	{
		glob->research[a] = 0;
		a++;
	}
}

t_control			*remove_cursor(t_control *control)
{
	t_lst			*tmp;

	if (dll_is_empty(control))
		return (control);
	tmp = control->begin;
	while (tmp != NULL)
	{
		tmp->cursor = 0;
		tmp = tmp->next;
	}
	return (control);
}
