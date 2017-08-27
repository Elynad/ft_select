/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:35:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/27 16:37:17 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		usage(void)
{
	ft_putstr_fd("Wrong arguments.\n", 2);
	ft_putstr_fd("Usage: ./ft_select [argument1] [argument2] ...\n", 2);
	exit(-1);
}
