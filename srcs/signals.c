/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:27:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 18:14:51 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		signal_handler(void)
{
	signal(SIGINT, signal_int);
	signal(SIGWINCH, signal_win);
}

void		signal_win(int signum)
{
	ioctl(0, TIOCGWINSZ, &glob->win);
	(void)signum;
	ft_debug("SIGNAL WINCH");
	printf("HEIGHT = %d | WIDTH = %d\n", glob->win.ws_row, glob->win.ws_col);
}

void		signal_int(int signum)
{
	(void)signum;
	ft_debug("SIGNAL INT");
}
