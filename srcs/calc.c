/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <mameyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 03:10:13 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/03 10:33:01 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		print_calc(t_control *control, int z)
{
	int			fillable_width;

	if (ioctl(0, TIOCGWINSZ, &glob->win) == -1)
		exit(EXIT_FAILURE);
	glob->longest_word = get_longest_word(control);
	fillable_width = glob->win.ws_col - 6;
	glob->spaces = (fillable_width / glob->longest_word) + 1;
	glob->words_per_line = (fillable_width / glob->longest_word) - z;
	if (glob->words_per_line <= 0)
		return ;
	if ((glob->longest_word * glob->words_per_line)
			+ (glob->spaces * (glob->words_per_line - 1)) > fillable_width)
		print_calc(control, (z + 1));
}

int			get_longest_word(t_control *control)
{
	t_lst		*tmp;
	size_t		longest;

	longest = 0;
	tmp = NULL;
	if (dll_is_empty(control))
		return (-1);
	else
	{
		tmp = control->begin;
		longest = ft_strlen(tmp->name);
		while (tmp != NULL)
		{
			if (ft_strlen(tmp->name) > longest)
				longest = ft_strlen(tmp->name);
			tmp = tmp->next;
		}
	}
	return (longest);
}

int			will_it_fit(void)
{
	int			total_size;
	int			term_size;

	total_size = glob->longest_word * glob->control->length;
	term_size = glob->win.ws_col * glob->win.ws_row;
	if ((glob->win.ws_col - 5 <= glob->longest_word)
		|| (term_size / 2 < total_size))
	{
		ft_debug("NOT ENOUGH SPACE");
		return (-1);
	}
	return (1);
}

void		print_interface(void)
{
	int		a;

	a = 0;
	while (a < (glob->longest_word * glob->words_per_line)
		+ ((glob->words_per_line - 1) * glob->spaces))
	{
		ft_putchar('=');
		a++;
	}
	ft_putchar('\n');
}
