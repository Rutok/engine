/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:09:07 by nboste            #+#    #+#             */
/*   Updated: 2017/02/08 00:39:33 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

void		init_camera(t_env *env, double rad_v_field, t_camera *camera)
{
	camera->ratio = env->win.size.x / env->win.size.y;
	camera->fov.y = rad_v_field;
	camera->d = 1.0 / tan(rad_v_field / 2);
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
		n.x = 0;
		n.y = 0;
	}
	return (n);
}

t_3dvertex	to_camera_space(t_3dvertex *v, t_camera *camera)
{
	t_3dvertex	n;

	n.x = v->x * camera->u.x + v->y * camera->u.y + v->z * camera->u.z;
	n.y = v->x * camera->v.x + v->y * camera->v.y + v->z * camera->u.z;
	n.z = v->x * camera->n.x + v->y * camera->n.y + v->z * camera->u.z;
	return (n);
}
