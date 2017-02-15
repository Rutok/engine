/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 05:15:39 by nboste            #+#    #+#             */
/*   Updated: 2017/02/15 23:18:03 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "libft.h"
# include "SDL2/SDL.h"

typedef enum		e_letters
{
	KEY_A = 0, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G,
	KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M, KEY_N, KEY_O,
	KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W,
	KEY_X, KEY_Y, KEY_Z
}					t_letters;

typedef struct		s_key_alphan
{
	t_bool	letters[26];
	t_bool	numbers[10];
}					t_key_alphan;

typedef enum		e_kp_keys
{
	KEY_KP_ENTER,
	KEY_KP_PERIOD,
	KEY_KP_PLUS,
	KEY_KP_MINUS,
	KEY_KP_MULTIPLY,
	KEY_KP_DIVIDE,
	KEY_KP_EQUALS,
	KEY_KP_CLEARNUMLOCK
}					t_kp_keys;

typedef struct		s_key_pad
{
	t_bool	numbers[10];
	t_bool	keys[10];
}					t_key_pad;

typedef enum		e_nav_keys
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_PAGEUP,
	KEY_PAGEDOWN,
	KEY_HOME,
	KEY_END,
	KEY_INSERT,
	KEY_DELETE
}					t_nav_keys;

typedef struct		s_key_nav
{
	t_bool	keys[10];
}					t_key_nav;

typedef enum		e_functions_keys
{
	KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5,
	KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10,
	KEY_F11, KEY_F12
}					t_functions_keys;

typedef struct		s_key_function
{
	t_bool	keys[12];
}					t_key_function;

typedef enum		e_specials_keys
{
	KEY_TAB,
	KEY_CAPSLOCK,
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_LCTRL,
	KEY_RCTRL,
	KEY_LALT,
	KEY_RALT,
	KEY_RETURN,
	KEY_BACKSPACE,
	KEY_SPACE,
	KEY_ESCAPE
}					t_specials_keys;

typedef struct		s_key_special
{
	t_bool	keys[12];
}					t_key_special;

typedef struct		s_mouse
{
	t_bool		move;
	t_bool		lclick;
	t_bool		rclick;
	t_2ipair	pos;
}					t_mouse;

typedef struct		s_event
{
	t_key_alphan	key_alphan;
	t_key_pad		key_pad;
	t_key_nav		key_nav;
	t_key_function	key_function;
	t_key_special	key_special;
	t_mouse			mouse;
	t_bool			focus;
	t_bool			exit;
	t_bool			in_use;
	t_bool			draw;
}					t_event;

void	event_process(t_event *event);

void	event_reset(t_event *event);

void	event_handle_keyboard(SDL_Event *ev, t_event *event);

void	event_handle_keyboard_key_pad(SDL_Keycode *k, t_event *event);

void	event_handle_keyboard_key_nav(SDL_Keycode *k, t_event *event);

void	event_handle_keyboard_key_function(SDL_Keycode *k, t_event *event);

void	event_handle_keyboard_key_special(SDL_Keycode *k, t_event *event);

void	event_handle_mouse(SDL_Event *ev, t_event *event);

int		handle_event(t_bool *e);

#endif
