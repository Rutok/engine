/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:09:07 by nboste            #+#    #+#             */
/*   Updated: 2017/02/19 08:29:22 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

void		init_camera(t_env *env, double rad_v_field, t_camera *camera)
{
	int		i;
	int		j;

	camera->ratio = env->win.size.x / env->win.size.y;
	camera->fov.y = rad_v_field;
	camera->d = 1.0 / tan(rad_v_field / 2);
	camera->size = env->win.size;
	camera->pixels = malloc(sizeof(t_pixel *) * camera->size.y);
	i = 0;
	while (i < camera->size.y)
	{
		camera->pixels[i] = malloc(sizeof(t_pixel) * camera->size.x);
		j = 0;
		while (j < camera->size.x)
		{
			camera->pixels[i][j].z_buffer = -1;
			j++;
		}
		i++;
	}
}

t_2dpair	camera_project_vertex(t_3dvertex *v, t_camera *camera)
{
	t_2dpair	n;

	if (v->z > 0)
	{
		n.x = (v->x * camera->d) / (v->z * camera->ratio);
		n.y = (v->y * camera->d) / v->z;
	}
	else if (v->z < 0)
	{
	//	n.x = -1;
		n.x = (v->x * camera->d) / (-v->z * camera->ratio);
		n.y = (v->y * camera->d) / -v->z;
	}
	else
	{
		n.x = (v->x * camera->d) /(camera->ratio);
		n.y = (v->y * camera->d);
	}
	return (n);
}

t_3dvertex	to_camera_space(t_3dvertex* v, t_camera *camera)
{
	t_3dvertex	p;
	t_3dvertex	s;

	p.x = v->x - camera->pos.x;
	p.y = v->y - camera->pos.y;
	p.z = v->z - camera->pos.z;
	s.x = p.x * camera->u.x + p.y * camera->u.y + p.z * camera->u.z;
	s.y = p.x * camera->v.x + p.y * camera->v.y + p.z * camera->v.z;
	s.z = p.x * camera->n.x + p.y * camera->n.y + p.z * camera->n.z;
	return (s);
}

void		reset_camera_pixels(t_camera *camera)
{
	t_2ipair	p;

	p.y = 0;
	while (p.y < camera->size.y)
	{
		p.x = 0;
		while (p.x < camera->size.x)
		{
			camera->pixels[p.y][p.x].z_buffer = -1;
			p.x++;
		}
		p.y++;
	}
}
