/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:09:07 by nboste            #+#    #+#             */
/*   Updated: 2017/02/08 04:00:52 by nboste           ###   ########.fr       */
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
		while (j < camera.size.x)
		{
			camera->pixels[i][j].z_buffer = 999999999999;
		}
		i++;
	}
}

t_2dpair	camera_project_vertex(t_3dvertex *v, t_camera *camera)
{
	t_2dpair	n;

	if (v->z != 0)
	{
		n.x = (v->x * camera->d) / (v->z * camera->ratio);
		n.y = (v->y * camera->d) / v->z;
	}
	else
	{
		n.x = -2;
		n.y = -2;
	}
	return (n);
}

void		to_camera_space(t_3dvertex* v, t_camera *camera)
{
	t_3dvertex	p;

	p.x = v->x - camera->pos.x;
	p.y = v->y - camera->pos.y;
	p.z = v->z - camera->pos.z;
	v->x = p.x * camera->u.x + p.y * camera->u.y + p.z * camera->u.z;
	v->y = p.x * camera->v.x + p.y * camera->v.y + p.z * camera->v.z;
	v->z = p.x * camera->n.x + p.y * camera->n.y + p.z * camera->n.z;
}
