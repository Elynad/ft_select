/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:25:27 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 18:12:33 by mameyer          ###   ########.fr       */
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

typedef struct			s_global
{
	t_control			*control;
	struct termios		term;
	struct termios		default_term;
	struct winsize		win;
	char				*term_name;
}						t_global;


/*
**		ERRORS
*/

void		set_usage(void);
void		empty_env(void);

/*
**		PARSING
*/

t_global	*parsing(char **argv);
void		init(void);

/*
**		CORE
*/

void		core(void);
void		events(char *str);

/*
**		PRINT
*/

void		print_list(t_control *control);
void		print_select(t_control *control);

/*
**		ACTIONS
*/

t_control		*set_cursor_prev(t_control *control);
t_control		*set_cursor_next(t_control *control);
t_control		*set_highlight(t_control *control);
t_control		*delete_elem(t_control *control);

/*
**		SIGNALS
*/

void		signal_handler(void);
void		signal_int(int signum);
void		signal_win(int signum);

struct s_global			*glob;

#endif
