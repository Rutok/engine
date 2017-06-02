/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_app.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 10:18:12 by nboste            #+#    #+#             */
/*   Updated: 2017/06/02 10:36:12 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_APP_H
# define TYPES_APP_H

# include <SDL2/SDL.h>
# include "libft.h"
# include "event.h"

typedef struct s_env	t_env;

typedef unsigned char	t_uchar;

typedef struct			s_win
{
	SDL_Window	*win_sdl;
	t_2ipair	size;
	char		*name;
	t_bool		focus;
}						t_win;

typedef struct			s_renderer
{
	SDL_Renderer	*rend_sdl;
	SDL_Texture		*texture_sdl;
	t_uint32		*pixels;
	t_2ipair		size;
	t_bool			draw;
}						t_renderer;

typedef struct			s_app
{
	void	(*init)(t_env *);
	int		(*process)(void *);
	void	(*destroy)(t_env *);
	void	*d;
	int		argc;
	char	**argv;
}						t_app;

struct					s_env
{
	t_win		win;
	t_event		event;
	t_renderer	rend;
	t_app		app;
};

typedef struct			s_color
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;
	t_uchar		a;
}						t_color;

#endif
