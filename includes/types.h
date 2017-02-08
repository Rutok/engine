/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 04:36:59 by nboste            #+#    #+#             */
/*   Updated: 2017/02/08 01:37:15 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <SDL2/SDL.h>
# include "libft.h"
# include "event.h"

/* ENGINE BASE */

typedef struct	s_env t_env;

typedef unsigned char	t_uchar;

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

/* 3D RENDERING */

typedef struct	s_scene t_scene;

typedef struct	s_color
{
	t_uchar		r;
	t_uchar		g;
	t_uchar		b;
	t_uchar		a;
}				t_color;

typedef struct	s_pixel
{
	double		z_buffer;
	t_color		color;
}				t_pixel;

typedef enum	e_projection_type
{
	parallel,
	perspective
}				t_projection_type;

typedef struct	s_camera
{
	t_3dvertex			pos;
	t_3dvertex			u;
	t_3dvertex			v;
	t_3dvertex			n;
	t_2dpair			fov;
	double				ratio;
	double				d;
	t_pixel				**pixels;
	t_2ipair			size;
	t_projection_type	projection;
}				t_camera;

typedef struct	s_object
{
	t_3dvertex	pos;
	t_3dvertex	dir;
	void		(*draw_obj)(t_scene *, struct s_object *);
	t_list		*triangles;
}				t_object;

typedef struct	s_scene
{
	t_camera	camera;
	t_list		*objects;
}				t_scene;

typedef struct	s_triangle
{
	t_3dvertex	a;
	t_3dvertex	b;
	t_3dvertex	c;
	t_3dvertex	n;
}				t_triangle;

#endif
