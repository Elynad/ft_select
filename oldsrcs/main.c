/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 02:23:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/29 06:41:25 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			main(int argc, char **argv)
{
	t_lst				*list;
	struct termios		term;
	struct termios		default_term;
	char				*term_name;

	if (argc < 2)
		set_usage();
	if (!(list = malloc(sizeof(t_lst))))
		exit(EXIT_FAILURE);
	list->next = NULL;
	parsing(list, argv);
	if ((term_name = getenv("TERM")) == NULL)
		no_env();
	if (tgetent(NULL, term_name) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &term) == -1 || tcgetattr(0, &default_term) == -1)
		exit (EXIT_FAILURE);
	init_term(&term);
	core(list);
	if (tcsetattr(0, TCSANOW, &default_term) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
