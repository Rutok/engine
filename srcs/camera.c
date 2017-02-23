/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:09:07 by nboste            #+#    #+#             */
/*   Updated: 2017/02/23 04:49:02 by nboste           ###   ########.fr       */
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

void		camera_project_vertex(t_3dvertex *v, t_2dpair *c_view, t_camera *camera)
{
	if (camera->projection == perspective)
	{
		if (v->z > 0)
		{
			c_view->x = (v->x * camera->d) / (v->z * camera->ratio);
			c_view->y = (v->y * camera->d) / v->z;
		}
		else if (v->z < 0)
		{
			c_view->x = (v->x * camera->d) / (-v->z * camera->ratio);
			c_view->y = (v->y * camera->d) / (-v->z);
		}
		else
		{
			c_view->x = (v->x * camera->d) /(camera->ratio);
			c_view->y = (v->y * camera->d);
		}
	c_view->x = round(((c_view->x + camera->ratio) * camera->size.x)  / (2 * camera->ratio));
	c_view->y = round(((c_view->y + 1) * camera->size.y)  / (2));
	}
	else
	{
			c_view->x = (v->x * camera->ratio) + (camera->size.x / 2);
			c_view->y = v->y + (camera->size.y / 2);
	}
}

void		to_camera_space(t_3dvertex* v, t_3dvertex* c_space, t_camera *camera)
{
	c_space->x = (v->x - camera->pos.x) * camera->u.x
		+ (v->y - camera->pos.y) * camera->u.y
		+ (v->z - camera->pos.z) * camera->u.z;
	c_space->y = (v->x - camera->pos.x) * camera->v.x
		+ (v->y - camera->pos.y) * camera->v.y
		+ (v->z - camera->pos.z) * camera->v.z;
	c_space->z = (v->x - camera->pos.x) * camera->n.x
		+ (v->y - camera->pos.y) * camera->n.y
		+ (v->z - camera->pos.z)* camera->n.z;
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
