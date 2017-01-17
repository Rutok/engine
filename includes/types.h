/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 04:36:59 by nboste            #+#    #+#             */
/*   Updated: 2017/01/17 02:26:42 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <SDL2/SDL.h>
# include "libft.h"
# include "event.h"

typedef struct	s_env t_env;

typedef struct	s_win
{
	SDL_Window	*win_sdl;
	t_2ipair	size;
	char		*name;
	t_bool		focus;
}				t_win;

typedef struct	s_renderer
{
	SDL_Renderer	*rend_sdl;
	SDL_Texture		*texture_sdl;
	uint32			*pixels;
	uint32			*pixels2;
	t_2ipair		size;
	t_bool			ready;
	t_bool			draw;
}				t_renderer;

typedef struct	s_app
{
	void	(*init)(t_env *);
	int		(*process)(void *);
	void	(*destroy)(t_env *);
	void	*d;
	int		argc;
	char	**argv;
}				t_app;

typedef struct s_env
{
	t_win		win;
	t_event		event;
	t_renderer	rend;
	t_app		app;
	SDL_Thread	*thread;
}				t_env;

#endif
