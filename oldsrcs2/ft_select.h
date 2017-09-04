/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 02:23:30 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/31 15:24:15 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include "../libft/libft.h"
# include "../libdll/libdll.h"
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>

typedef struct			s_glob
{
	t_lst				*list;
}						t_glob;

/*
**		CORE
*/

void			core(t_control *control);

/*
**		INIT
*/


/*
**		PRINT
*/

void			print_list(t_control *control, char sep);
void			print_highlight(t_control *control);

/*
**		PARSING
*/

t_control		*parsing(char **argv);

/*
**		EVENTS
*/

void			events(char *str, t_control *control);

/*
**		ERRORS
*/

void		set_usage(void);
void		empty_env(void);

/*
**		LINKED LISTS
*/


/*
**		OPTIONS
*/

t_control		*set_cursor_prev(t_control *control);
t_control		*set_cursor_next(t_control *control);
t_control		*set_highlight(t_control *control);
t_control		*delete_elem(t_control *control);

/*
**		GLOBAL VAR
*/

struct s_glob			global;

#endif
