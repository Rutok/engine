/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:09:07 by nboste            #+#    #+#             */
/*   Updated: 2017/03/04 03:00:14 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

void		init_camera(t_env *env, double rad_v_field, t_camera *camera)
{
	camera->ratio = env->win.size.x / env->win.size.y;
	camera->fov.y = rad_v_field;
	camera->d = 1.0 / tan(rad_v_field / 2);
	camera->size = env->win.size;
	camera->z_buffer = malloc(sizeof(uint32 *) * camera->size.y * camera->size.x);
	reset_camera_pixels(camera);
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
	ft_memset(camera->z_buffer, 0, sizeof(uint32) * camera->size.x * camera->size.y);
}
