/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 05:33:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/27 22:22:42 by mameyer          ###   ########.fr       */
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

/*
**		PARSING
*/

int			*init_highlight_tab(int argc);

/*
**		CORE
*/

void		core(char **argv, int argc, int *highlight, int cursor_pos);
void		set_cursor_pos(char *str, int *cursor_pos, int argc);

/*
**		PRINT
*/

void		sel_print(char **arguments, int cursor_pos, int *highlight);
void		print_str(char *argument, int cursor_pos, int highlight);

/*
**		ERRORS
*/

void		usage(void);

#endif
