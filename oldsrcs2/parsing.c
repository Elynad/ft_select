/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 06:51:27 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/30 07:47:05 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_control		*parsing(char **argv)
{
	t_control	*control;
	int			a;

	a = 1;
	control = NULL;
	while (argv[a])
	{
		control = dll_add_new_elem_end(control, argv[a]);
		a++;
	}
	control->begin->cursor = 1;
	return (control);
}
