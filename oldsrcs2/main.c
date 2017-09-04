/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 06:35:04 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 14:45:25 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static void		handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)siginfo;
	(void)context;
	ft_debug("IN HANDLER");
}

int			main(int argc, char **argv)
{
	struct termios			term;
	struct termios			default_term;
	t_control				*control;
	char					*term_name;

	control = NULL;
	if (argc < 2)
		set_usage();
	control = parsing(argv);
	if ((term_name = getenv("TERM")) == NULL)
		empty_env();
	if (tgetent(NULL, term_name) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &term) == -1 || tcgetattr(0, &default_term) == -1)
		exit(EXIT_FAILURE);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		exit(EXIT_FAILURE);

//	signal(SIGINT, &get_new_winsize);
	struct sigaction		act;
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &act, NULL) < 0)
	{
		ft_debug("SIGACTION ERROR");
	}

	core(control);
	if (tcsetattr(0, TCSANOW, &default_term) == -1)			// SET DEFAULT TERM
		exit(EXIT_FAILURE);
	return (0);
}
