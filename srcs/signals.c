/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <mameyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:27:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/03 22:54:55 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		signal_handler(void)
{
	signal(SIGINT, signal_int);
	signal(SIGWINCH, signal_win);
	signal(SIGTSTP, signal_stp);
	signal(SIGCONT, signal_cont);
}

void		signal_cont(int signum)
{
	(void)signum;
	init();
	print_list(glob->control);
	signal(SIGTSTP, signal_stp);
}

void		signal_stp(int signum)
{
	char		cmd[2];

	tcsetattr(0, TCSANOW, &glob->default_term);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		cmd[0] = glob->default_term.c_cc[VSUSP];
		cmd[1] = '\0';
		ioctl(0, TIOCSTI, cmd);
	}
}

void		signal_win(int signum)
{
	char		*res;

	res = NULL;
	ioctl(0, TIOCGWINSZ, &glob->new_win);
	if (glob->new_win.ws_row != glob->win.ws_row
			|| glob->new_win.ws_col != glob->win.ws_col)
	{
		if ((res = tgetstr("cl", NULL)) == NULL)
			exit(EXIT_FAILURE);
		ft_putstr_fd(res, 1);
		print_list(glob->control);
	}
	(void)signum;
}

void		signal_int(int signum)
{
	(void)signum;
	glob->control = dll_clear_list(glob->control);
	if (tcsetattr(0, TCSANOW, &glob->default_term) == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
