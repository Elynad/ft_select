/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:22:29 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 17:54:33 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			main(int argc, char **argv)
{
	if (argc < 2)
		set_usage();
	if (!(glob = malloc(sizeof(t_global))))
		exit(EXIT_FAILURE);
	glob = parsing(argv);
	init();
	signal_handler();
	core();
	if (tcsetattr(0, TCSANOW, &glob->default_term) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
