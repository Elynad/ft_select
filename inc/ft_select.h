/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 05:33:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/28 18:02:55 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include "../libft/libft.h"
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdio.h>
# include <sys/ioctl.h>

typedef struct			s_lst
{
	char				*name;
	int					highlight;
	int					cursor;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

/*
**		PARSING
*/

t_lst		*parsing(char **argv);
void		set_elem(t_lst *begin, char *str);
int			*init_highlight_tab(int argc);

/*
**		CORE
*/

void		core(t_lst *list);
void		events(char *str, t_lst *list);

/*
**		EVENTS
*/

void		set_cursor_prev(t_lst *list);
void		set_cursor_next(t_lst *list);
void		set_highlight(t_lst *list);
t_lst		*delete_elem(t_lst *list);

/*
**		PRINT
*/

void		print_list(t_lst *begin, char sep);
void		sel_print(char **arguments, int cursor_pos, int *highlight);
void		print_str(char *argument, int cursor_pos, int highlight);

/*
**		ERRORS
*/

void		usage(void);

/*
**		OTHER
*/

void		free_list(t_lst *list);

#endif
