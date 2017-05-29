/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:09:07 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 17:05:05 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

void	init_camera(t_env *env, double rad_v_field, t_camera *camera)
{
	camera->ratio = env->win.size.x / env->win.size.y;
	camera->fov.y = rad_v_field;
	camera->d = 1.0 / tan(rad_v_field / 2);
	camera->size = env->win.size;
	camera->z_buffer = malloc(sizeof(t_uint32 *)
								* camera->size.y * camera->size.x);
	reset_camera_pixels(camera);
}

void	camera_project_vertex(t_3dvertex *v, t_2dpair *c_view, t_camera *cam)
{
	if (cam->projection == perspective)
	{
		if (v->z > 0)
		{
			c_view->x = (v->x * cam->d) / (v->z * cam->ratio);
			c_view->y = -(v->y * cam->d) / v->z;
			c_view->x = round(((c_view->x + cam->ratio) * cam->size.x)
								/ (2 * cam->ratio));
			c_view->y = round(((c_view->y + 1) * cam->size.y) / (2));
		}
		else
		{
			c_view->x = -99;
			c_view->y = -99;
		}
	}
	else
	{
		c_view->x = (v->x * cam->ratio) + (cam->size.x / 2);
		c_view->y = -v->y + (cam->size.y / 2);
	}
}

t_bool	to_camera_space(t_3dvertex *v, t_3dvertex *c_space, t_camera *camera)
{
	c_space->x = (v->x - camera->pos.x) * camera->u.x
		+ (v->y - camera->pos.y) * camera->u.y
		+ (v->z - camera->pos.z) * camera->u.z;
	c_space->y = (v->x - camera->pos.x) * camera->v.x
		+ (v->y - camera->pos.y) * camera->v.y
		+ (v->z - camera->pos.z) * camera->v.z;
	c_space->z = (v->x - camera->pos.x) * camera->n.x
		+ (v->y - camera->pos.y) * camera->n.y
		+ (v->z - camera->pos.z) * camera->n.z;
	if (c_space->z <= 0 || c_space->z > camera->range)
		return (0);
	return (1);
}

void	reset_camera_pixels(t_camera *c)
{
	ft_memset(c->z_buffer, 0, sizeof(t_uint32) * c->size.x * c->size.y);
}
