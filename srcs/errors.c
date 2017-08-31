/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:26:09 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 16:10:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		set_usage(void)
{
	ft_putstr_fd("No arguments.\n", 2);
	ft_putstr_fd("Usage: ./ft_select [argument1] [argument2] ...\n", 2);
	exit(EXIT_FAILURE);
}

void		empty_env(void)
{
	ft_putstr_fd("Error: Empty environment.\n", 2);
	exit(EXIT_FAILURE);
}
