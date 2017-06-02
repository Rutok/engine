/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:15:18 by nboste            #+#    #+#             */
/*   Updated: 2017/06/02 10:44:18 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	event_process(t_event *event)
{
	SDL_Event	ev;

	while (SDL_PollEvent(&ev))
	{
		if (event->focus)
		{
			if (ev.type == SDL_QUIT)
				event->exit = 1;
			else if (ev.type == SDL_MOUSEMOTION || ev.type == SDL_MOUSEBUTTONUP)
				event_handle_mouse(&ev, event);
		}
		if (ev.type == SDL_WINDOWEVENT
				&& ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
			event->focus = 1;
		else if (ev.type == SDL_WINDOWEVENT
				&& ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
			event->focus = 0;
	}
	if (event->focus)
		event->keys = SDL_GetKeyboardState(NULL);
}

void	event_reset(t_event *event)
{
	event->exit = 0;
	event->focus = 1;
	event->draw = 0;
}

void	event_handle_mouse(SDL_Event *ev, t_event *event)
{
	if (ev->type == SDL_MOUSEMOTION)
	{
		event->mouse.move = 1;
		event->mouse.pos.x = ev->motion.x;
		event->mouse.pos.y = ev->motion.y;
	}
	else
	{
		event->mouse.lclick = 1;
		event->mouse.pos.x = ev->button.x;
		event->mouse.pos.y = ev->button.y;
	}
}

int		handle_event(t_bool *e)
{
	if (*e)
	{
		*e = 0;
		return (1);
	}
	return (0);
}
