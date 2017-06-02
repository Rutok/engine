/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 04:36:59 by nboste            #+#    #+#             */
/*   Updated: 2017/06/02 10:37:07 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "types_app.h"

typedef struct			s_uvn
{
	t_3dvertex			u;
	t_3dvertex			v;
	t_3dvertex			n;
}						t_uvn;

typedef enum			e_projection_type
{
	parallel,
	perspective
}						t_projection_type;

typedef struct			s_camera
{
	t_3dvertex			pos;
	t_3dvertex			u;
	t_3dvertex			v;
	t_3dvertex			n;
	t_2dpair			fov;
	double				ratio;
	double				d;
	t_uint32			*z_buffer;
	t_2ipair			size;
	t_projection_type	projection;
	double				speed;
	double				sensitivity;
	int					range;
}						t_camera;

typedef struct			s_vertexes
{
	t_uint32	size;
	t_3dvertex	*v;
	t_3dvertex	*v2;
}						t_vertexes;

typedef struct			s_3dobject
{
	t_3dvertex	pos;
	t_uvn		uvn;
	t_3dvertex	scale;
	t_list		*faces;
	t_vertexes	vertexes;
	t_color		(*get_color)(int);
}						t_3dobject;

typedef struct			s_scene
{
	t_camera	camera;
	t_list		*objects;
}						t_scene;

typedef struct			s_face
{
	t_uint32	v1;
	t_uint32	v2;
	t_uint32	v3;
	t_2dpair	vt1;
	t_3dvertex	vn1;
	t_2dpair	vt2;
	t_3dvertex	vn2;
	t_2dpair	vt3;
	t_3dvertex	vn3;
	t_color		c1;
	t_color		c2;
	t_color		c3;
}						t_face;

typedef struct			s_point
{
	t_2ipair	pos;
	double		z;
	t_color		c;
}						t_point;

#endif
