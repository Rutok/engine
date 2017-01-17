/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 02:35:37 by nboste            #+#    #+#             */
/*   Updated: 2017/01/17 02:35:45 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

static void		key_pad_next(SDL_Keycode *k, t_event *event);

void			event_handle_keyboard_key_pad(SDL_Keycode *k, t_event *event)
{
	if (*k == SDLK_KP_0)
		event->key_pad.numbers[0] = 1;
	else if (*k == SDLK_KP_1)
		event->key_pad.numbers[1] = 1;
	else if (*k == SDLK_KP_2)
		event->key_pad.numbers[2] = 1;
	else if (*k == SDLK_KP_3)
		event->key_pad.numbers[3] = 1;
	else if (*k == SDLK_KP_4)
		event->key_pad.numbers[4] = 1;
	else if (*k == SDLK_KP_5)
		event->key_pad.numbers[5] = 1;
	else if (*k == SDLK_KP_6)
		event->key_pad.numbers[6] = 1;
	else if (*k == SDLK_KP_7)
		event->key_pad.numbers[7] = 1;
	else if (*k == SDLK_KP_8)
		event->key_pad.numbers[8] = 1;
	else if (*k == SDLK_KP_9)
		event->key_pad.numbers[9] = 1;
	else
		key_pad_next(k, event);
}

static void		key_pad_next(SDL_Keycode *k, t_event *event)
{
	if (*k == SDLK_NUMLOCKCLEAR)
		event->key_pad.keys[KEY_KP_CLEARNUMLOCK] = 1;
	else if (*k == SDLK_KP_EQUALS)
		event->key_pad.numbers[KEY_KP_EQUALS] = 1;
	else if (*k == SDLK_KP_DIVIDE)
		event->key_pad.numbers[KEY_KP_DIVIDE] = 1;
	else if (*k == SDLK_KP_MULTIPLY)
		event->key_pad.numbers[KEY_KP_MULTIPLY] = 1;
	else if (*k == SDLK_KP_MINUS)
		event->key_pad.numbers[KEY_KP_MINUS] = 1;
	else if (*k == SDLK_KP_PLUS)
		event->key_pad.numbers[KEY_KP_PLUS] = 1;
	else if (*k == SDLK_KP_PERIOD)
		event->key_pad.numbers[KEY_KP_PERIOD] = 1;
	else if (*k == SDLK_KP_ENTER)
		event->key_pad.numbers[KEY_KP_ENTER] = 1;
}

void			event_handle_keyboard_key_nav(SDL_Keycode *k, t_event *event)
{
	if (*k == SDLK_UP)
		event->key_nav.keys[KEY_UP] = 1;
	else if (*k == SDLK_DOWN)
		event->key_nav.keys[KEY_DOWN] = 1;
	else if (*k == SDLK_LEFT)
		event->key_nav.keys[KEY_LEFT] = 1;
	else if (*k == SDLK_RIGHT)
		event->key_nav.keys[KEY_RIGHT] = 1;
	else if (*k == SDLK_PAGEUP)
		event->key_nav.keys[KEY_PAGEUP] = 1;
	else if (*k == SDLK_PAGEDOWN)
		event->key_nav.keys[KEY_PAGEDOWN] = 1;
	else if (*k == SDLK_HOME)
		event->key_nav.keys[KEY_HOME] = 1;
	else if (*k == SDLK_END)
		event->key_nav.keys[KEY_END] = 1;
	else if (*k == SDLK_INSERT)
		event->key_nav.keys[KEY_INSERT] = 1;
	else if (*k == SDLK_DELETE)
		event->key_nav.keys[KEY_DELETE] = 1;
}

void	event_handle_keyboard_key_function(SDL_Keycode *k, t_event *event)
{
	if (*k == SDLK_F1)
		event->key_function.keys[KEY_F1] = 1;
	else if (*k == SDLK_F2)
		event->key_function.keys[KEY_F2] = 1;
	else if (*k == SDLK_F3)
		event->key_function.keys[KEY_F3] = 1;
	else if (*k == SDLK_F4)
		event->key_function.keys[KEY_F4] = 1;
	else if (*k == SDLK_F5)
		event->key_function.keys[KEY_F5] = 1;
	else if (*k == SDLK_F6)
		event->key_function.keys[KEY_F6] = 1;
	else if (*k == SDLK_F7)
		event->key_function.keys[KEY_F7] = 1;
	else if (*k == SDLK_F8)
		event->key_function.keys[KEY_F8] = 1;
	else if (*k == SDLK_F9)
		event->key_function.keys[KEY_F9] = 1;
	else if (*k == SDLK_F10)
		event->key_function.keys[KEY_F10] = 1;
	else if (*k == SDLK_F11)
		event->key_function.keys[KEY_F11] = 1;
	else if (*k == SDLK_F12)
		event->key_function.keys[KEY_F12] = 1;
}

void	event_handle_keyboard_key_special(SDL_Keycode *k, t_event *event)
{
	if (*k == SDLK_TAB)
		event->key_special.keys[KEY_TAB] = 1;
	else if (*k == SDLK_CAPSLOCK)
		event->key_special.keys[KEY_CAPSLOCK] = 1;
	else if (*k == SDLK_LSHIFT)
		event->key_special.keys[KEY_LSHIFT] = 1;
	else if (*k == SDLK_RSHIFT)
		event->key_special.keys[KEY_RSHIFT] = 1;
	else if (*k == SDLK_LCTRL)
		event->key_special.keys[KEY_LCTRL] = 1;
	else if (*k == SDLK_RCTRL)
		event->key_special.keys[KEY_RCTRL] = 1;
	else if (*k == SDLK_LALT)
		event->key_special.keys[KEY_LALT] = 1;
	else if (*k == SDLK_RALT)
		event->key_special.keys[KEY_RALT] = 1;
	else if (*k == SDLK_RETURN)
		event->key_special.keys[KEY_RETURN] = 1;
	else if (*k == SDLK_BACKSPACE)
		event->key_special.keys[KEY_BACKSPACE] = 1;
	else if (*k == SDLK_SPACE)
		event->key_special.keys[KEY_SPACE] = 1;
	else if (*k == SDLK_ESCAPE)
		event->key_special.keys[KEY_ESCAPE] = 1;
}
