/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 02:03:37 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 17:05:28 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "camera_drawer.h"

static void		to_obj_space(t_3dvertex v, t_3dvertex *o_space, t_3dobject *obj)
{
	t_uvn	*d;

	d = &obj->uvn;
	o_space->x = ((v.x * d->n.x * obj->scale.x)  + (v.y * d->n.y * obj->scale.y) + (v.z  * d->n.z * obj->scale.z) + obj->pos.x);
	o_space->y = ((v.x * d->u.x * obj->scale.x)  + (v.y * d->u.y * obj->scale.y)  + (v.z * d->u.z * obj->scale.z) + obj->pos.y);
	o_space->z = ((v.x * d->v.x * obj->scale.x)  + (v.y  * d->v.y * obj->scale.y) + (v.z * d->v.z * obj->scale.z) + obj->pos.z);
}

int		camera_draw_3dobject(t_3dobject *obj, t_camera *cam, t_env *env)
{
	t_list		*l;
	t_face		*f;
	t_3dvertex	c1;
	t_2dpair	c_view;
	t_point		p1, p2, p3;
	t_uint32		i;
	t_vertexes	v;

	i = 0;
	v.v = obj->vertexes.v2;
	while (i < obj->vertexes.size)
	{
		to_obj_space(obj->vertexes.v[i], &v.v[i], obj);
		c1 = v.v[i];
		to_camera_space(&c1, &v.v[i], cam);
		i++;
	}
	l = obj->faces;
	while (l)
	{
		f = (t_face *)l->content;
		if ((v.v[f->v1].z > 0 && v.v[f->v2].z > 0 && v.v[f->v3].z > 0)
				&& (v.v[f->v1].z < cam->range && v.v[f->v2].z < cam->range && v.v[f->v3].z < cam->range))
		{
			p1.z = (v.v[f->v1].x * v.v[f->v1].x)
				+ (v.v[f->v1].y * v.v[f->v1].y)
				+ (v.v[f->v1].z * v.v[f->v1].z);
			p2.z = (v.v[f->v2].x * v.v[f->v2].x)
				+ (v.v[f->v2].y * v.v[f->v2].y)
				+ (v.v[f->v2].z * v.v[f->v2].z);
			p3.z = (v.v[f->v3].x * v.v[f->v3].x)
				+ (v.v[f->v3].y * v.v[f->v3].y)
				+ (v.v[f->v3].z * v.v[f->v3].z);
			p1.c = obj->getColor(obj->vertexes.v[f->v1].z);
			p2.c = obj->getColor(obj->vertexes.v[f->v2].z);
			p3.c = obj->getColor(obj->vertexes.v[f->v3].z);
			camera_project_vertex(&v.v[f->v1], &c_view, cam);
			p1.pos.x = c_view.x;
			p1.pos.y = c_view.y;
			camera_project_vertex(&v.v[f->v2], &c_view, cam);
			p2.pos.x = c_view.x;
			p2.pos.y = c_view.y;
			camera_project_vertex(&v.v[f->v3], &c_view, cam);
			p3.pos.x = c_view.x;
			p3.pos.y = c_view.y;
			camera_draw_line(&p1, &p2, cam, env);
			camera_draw_line(&p1, &p3, cam, env);
		}
		l = l->next;
	}
	return (1);
}
