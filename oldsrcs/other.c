/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 05:22:35 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 05:27:15 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		free_list(t_lst *list)
{
	t_lst		*tmp;

	tmp = NULL;
	if (list)
	{
		if (list->next)
			tmp = list->next;
		free(list->name);
		free(list);
	}
	if (tmp)
		free_list(tmp);
}
