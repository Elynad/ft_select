/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 07:03:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/30 14:43:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		core(t_control *control)
{
	char				*res;
	char				str[4];

	str[3] = '\0';
	print_list(control, '\n');
	while (read(0, str, 3))
	{
		if ((res = tgetstr("cl", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		events(str, control);
		ft_putendl("<----------");
		print_list(control, '\n');
		ft_putendl("---------->");
	}
}
