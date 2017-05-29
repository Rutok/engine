/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:15:39 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 12:53:26 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "libft.h"
# include "SDL2/SDL.h"

typedef struct		s_mouse
{
	t_bool		move;
	t_bool		lclick;
	t_bool		rclick;
	t_2ipair	pos;
}					t_mouse;

typedef struct		s_event
{
	const Uint8		*keys;
	t_mouse			mouse;
	t_bool			focus;
	t_bool			exit;
	t_bool			in_use;
	t_bool			draw;
}					t_event;

void				event_process(t_event *event);

void				event_reset(t_event *event);

void				event_handle_mouse(SDL_Event *ev, t_event *event);

int					handle_event(t_bool *e);

#endif
