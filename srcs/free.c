/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:14:58 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/28 13:16:50 by mameyer          ###   ########.fr       */
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
		free_list(tmp);
	}
}
