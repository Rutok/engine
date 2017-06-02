/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 02:03:37 by nboste            #+#    #+#             */
/*   Updated: 2017/06/02 11:23:10 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "camera_drawer.h"

static void		to_obj_space(t_3dvertex v, t_3dvertex *o_space, t_3dobject *obj)
{
	t_uvn	*d;

	d = &obj->uvn;
	o_space->x = ((v.x * d->n.x * obj->scale.x) + (v.y * d->n.y * obj->scale.y)
			+ (v.z * d->n.z * obj->scale.z) + obj->pos.x);
	o_space->y = ((v.x * d->u.x * obj->scale.x) + (v.y * d->u.y * obj->scale.y)
			+ (v.z * d->u.z * obj->scale.z) + obj->pos.y);
	o_space->z = ((v.x * d->v.x * obj->scale.x) + (v.y * d->v.y * obj->scale.y)
			+ (v.z * d->v.z * obj->scale.z) + obj->pos.z);
}

static double	get_norm(int nb, t_3dvertex *v)
{
	return ((v[nb].x * v[nb].x) + (v[nb].y * v[nb].y) + (v[nb].z * v[nb].z));
}

static void		fill_norm_color(t_point *p, t_3dobject *obj, t_face *f)
{
	p[0].z = get_norm(f->v1, obj->vertexes.v2);
	p[1].z = get_norm(f->v2, obj->vertexes.v2);
	p[2].z = get_norm(f->v3, obj->vertexes.v2);
	p[0].c = obj->get_color(obj->vertexes.v[f->v1].z);
	p[1].c = obj->get_color(obj->vertexes.v[f->v2].z);
	p[2].c = obj->get_color(obj->vertexes.v[f->v3].z);
}

static void		draw_faces(t_face *f, t_3dobject *obj,
		t_camera *cam, t_env *env)
{
	t_2dpair	c_view;
	t_point		p[3];
	t_vertexes	v;

	v.v = obj->vertexes.v2;
	if ((v.v[f->v1].z > 0 && v.v[f->v2].z > 0 && v.v[f->v3].z > 0)
			&& (v.v[f->v1].z < cam->range && v.v[f->v2].z < cam->range
				&& v.v[f->v3].z < cam->range))
	{
		fill_norm_color(p, obj, f);
		camera_project_vertex(&v.v[f->v1], &c_view, cam);
		p[0].pos.x = c_view.x;
		p[0].pos.y = c_view.y;
		camera_project_vertex(&v.v[f->v2], &c_view, cam);
		p[1].pos.x = c_view.x;
		p[1].pos.y = c_view.y;
		camera_project_vertex(&v.v[f->v3], &c_view, cam);
		p[2].pos.x = c_view.x;
		p[2].pos.y = c_view.y;
		camera_draw_line(&p[0], &p[1], cam, env);
		camera_draw_line(&p[0], &p[2], cam, env);
	}
}

int				camera_draw_3dobject(t_3dobject *obj, t_camera *cam, t_env *env)
{
	t_list		*l;
	t_3dvertex	c1;
	t_uint32	i;
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
		draw_faces(l->content, obj, cam, env);
		l = l->next;
	}
	return (1);
}
