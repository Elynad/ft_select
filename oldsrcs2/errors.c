/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 06:50:02 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/30 07:03:10 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			set_usage(void)
{
	ft_putstr_fd("Wrong arguments for ft_select.\n", 2);
	ft_putstr_fd("Usage: ./ft_select [argument1] [argument2] ...\n", 2);
	exit(EXIT_FAILURE);
}

void			empty_env(void)
{
	ft_putstr_fd("Error: Environment empty.\n", 2);
	exit(EXIT_FAILURE);
}
