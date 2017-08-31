/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:31:07 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 18:13:57 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_global		*parsing(char **argv)
{
	int				a;

	a = 1;
	glob->control = NULL;
	while (argv[a])
	{
		glob->control = dll_add_new_elem_end(glob->control, argv[a]);
		a++;
	}
	glob->control->begin->cursor = 1;
	return (glob);
}

void			init(void)
{
	if ((glob->term_name = getenv("TERM")) == NULL)
		empty_env();
	if (tgetent(NULL, glob->term_name) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &glob->term) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &glob->default_term) == -1)
		exit(EXIT_FAILURE);
	glob->term.c_lflag &= ~(ICANON);
	glob->term.c_lflag &= ~(ECHO);
	glob->term.c_cc[VMIN] = 1;
	glob->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &glob->term) == -1)
		exit(EXIT_FAILURE);
}
