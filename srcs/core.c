/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:10:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/01 00:25:29 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		core(void)
{
	char		*res;
	char		str[4];

	str[3] = '\0';
	print_list(glob->control);
	init_search_char();
	while (read(0, str, 3))
	{
		if ((res = tgetstr("cl", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		if ((str[0] >= 33 && str[0] <= 127) || str[0] == 127)
			glob->control = research(str, glob->control);
		else
		{
			init_search_char();
			events(str);
		}
		print_list(glob->control);
	}
}
