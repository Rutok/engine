/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:15:18 by nboste            #+#    #+#             */
/*   Updated: 2017/01/17 02:34:06 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	event_process(t_event *event)
{
	SDL_Event	ev;

	while (event->in_use) { SDL_Delay(2);}
	event->in_use = 1;
	while (SDL_PollEvent(&ev))
	{
		if (event->focus)
		{
			if (ev.type == SDL_QUIT)
				event->exit = 1;
			else if (ev.type == SDL_KEYDOWN)
				event_handle_keyboard(&ev, event);
			else if (ev.type == SDL_MOUSEMOTION || ev.type == SDL_MOUSEBUTTONUP)
				event_handle_mouse(&ev, event);
		}
		if (ev.type == SDL_WINDOWEVENT && ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
			event->focus = 1;
		else if (ev.type == SDL_WINDOWEVENT && ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
			event->focus = 0;
	}
	event->in_use = 0;
}

void	event_reset(t_event *event)
{
	int		i;

	event->exit = 0;
	event->focus = 0;
	event->draw = 0;
	i = 0;
	while (i < 26)
	{
		event->key_alphan.letters[i] = 0;
		if (i < 12)
		{
			event->key_function.keys[i] = 0;
			event->key_special.keys[i] = 0;
		}
		if (i < 10)
		{
			event->key_alphan.numbers[i] = 0;
			event->key_pad.numbers[i] = 0;
			event->key_nav.keys[i] = 0;
			event->key_pad.keys[i] = 0;
		}
		i++;
	}
}

void	event_handle_keyboard(SDL_Event *ev, t_event *event)
{
	SDL_Keycode	k;

	k = ev->key.keysym.sym;
	if (k >= 'a' && k <= 'z')
		event->key_alphan.letters[k - 'a'] = 1;
	else if (k >= '0' && k <= '9')
		event->key_alphan.numbers[k - '0'] = 1;
	else
	{
		event_handle_keyboard_key_pad(&k, event);
		event_handle_keyboard_key_nav(&k, event);
		event_handle_keyboard_key_function(&k, event);
		event_handle_keyboard_key_special(&k, event);
	}
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
