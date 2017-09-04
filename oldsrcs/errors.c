/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 02:31:57 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 04:17:26 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		set_usage(void)
{
	ft_putstr_fd("Wrong arguments for ./ft_select\n", 2);
	ft_putstr_fd("Usage: ./ft_select [argument1] [argument2] ...\n", 2);
	exit(EXIT_FAILURE);
}

void		no_env(void)
{
	ft_putstr_fd("Error: Empty environment.\n", 2);
	exit(EXIT_FAILURE);
}
