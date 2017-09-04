/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <mameyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:25:27 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/03 22:30:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include "../libft/libft.h"
# include "../libdll/libdll.h"
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>

# define UP_ARROW 'A'
# define DOWN_ARROW 'B'
# define RIGHT_ARROW 'C'
# define LEFT_ARROW 'D'

typedef struct			s_global
{
	t_control			*control;
	struct termios		term;
	struct termios		default_term;
	struct winsize		win;
	struct winsize		new_win;
	char				*term_name;
	char				research[50];
	int					words_per_line;
	int					longest_word;
	int					spaces;
}						t_global;

/*
**		ERRORS
*/

void					set_usage(void);
void					empty_env(void);

/*
**		PARSING
*/

t_global				*parsing(char **argv);
void					init(void);

/*
**		CORE
*/

void					core(void);
void					events(char *str);

/*
**		PRINT
*/

void					print_list(t_control *control);
void					print_select(t_control *control);
void					print_single_elem(t_lst *elem);
void					print_spaces(t_lst *elem);
void					print_interface(void);

/*
**		ACTIONS
*/

t_control				*set_cursor_prev(t_control *control);
t_control				*set_cursor_next(t_control *control);
t_control				*set_cursor_below(t_control *control);
t_control				*set_cursor_above(t_control *control);
t_control				*set_cursor_above_2(t_control *control, t_lst *elem);
t_control				*set_cursor_below_2(t_control *control, t_lst *elem);
t_control				*set_highlight(t_control *control);
t_control				*delete_elem(t_control *control);
t_control				*delete_manager(t_control *control, t_lst *elem);
t_control				*del_last_elem(t_control *control, t_lst *elem);
t_control				*del_first_elem(t_control *control, t_lst *elem);
void					del_only_elem(t_lst *elem);
t_control				*del_regular_elem(t_control *control, t_lst *elem);

/*
**		SIGNALS
*/

void					signal_handler(void);
void					signal_int(int signum);
void					signal_win(int signum);
void					signal_stp(int signum);
void					signal_cont(int signum);

/*
**		CALC
*/

void					print_calc(t_control *control, int z);
int						get_longest_word(t_control *control);
int						will_it_fit(void);
void					calc_print_size(t_control *control);

/*
**		DYNAMIC SEARCH
*/

void					init_search_char(void);
void					add_char(char c);
t_control				*remove_cursor(t_control *control);
t_control				*research(char *str, t_control *control);

struct s_global			*glob;

#endif
