/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 04:22:32 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 06:44:06 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		core(t_lst *list)
{
	char		str[4];
	char		*res;

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
