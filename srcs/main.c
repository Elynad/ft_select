/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 16:34:20 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/27 22:15:27 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int		main(int argc, char **argv)
{
	struct termios		term;
	struct termios		default_term;
	char				*term_name;
	int					*highlight;

	if (argc < 2)
		usage();
	if ((term_name = getenv("TERM")) == NULL)
		exit(EXIT_FAILURE);
	if (tgetent(NULL, term_name) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &term) == -1 || tcgetattr(0, &default_term) == -1)
		exit(EXIT_FAILURE);
	term.c_lflag &= ~(ICANON);							// SET CANONIC MODE
	term.c_lflag &= ~(ECHO);							// INVISIBLE KEYS
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		exit(EXIT_FAILURE);
	highlight = init_highlight_tab(argc);
	core(argv, argc, highlight, 0);
	if (tcsetattr(0, TCSANOW, &default_term) == -1)		// SET DEFAULT TERM
		exit(EXIT_FAILURE);
	return (0);
}

int		*init_highlight_tab(int argc)
{
	int		*highlight;
	int		a;

	a = 0;
	if (!(highlight = (int *)malloc(sizeof(int) * argc)))
		exit(EXIT_FAILURE);
	while (highlight[a])
	{
		highlight[a] = 0;
		a++;
	}
	return (highlight);
}
