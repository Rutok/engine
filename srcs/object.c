/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 02:03:37 by nboste            #+#    #+#             */
/*   Updated: 2017/03/19 16:48:53 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "camera_drawer.h"

static void		to_obj_space(t_3dvertex v, t_3dvertex *o_space, t_3dobject *obj)
{
	t_uvn	*d;

	d = &obj->uvn;
	o_space->x = (v.x - obj->pos.x) * d->u.x + (v.y - obj->pos.y) * d->u.y + (v.z - obj->pos.z) * d->u.z;
	o_space->y = (v.x - obj->pos.x) * d->v.x + (v.y - obj->pos.y) * d->v.y + (v.z - obj->pos.z) * d->v.z;
	o_space->z = (v.x - obj->pos.x) * d->n.x + (v.y - obj->pos.y) * d->n.y + (v.z - obj->pos.z) * d->n.z;
}

static void		face_to_obj_space(t_face *f, t_3dobject *obj)
{
	to_obj_space(f->v1, &f->v1, obj);
	to_obj_space(f->v2, &f->v2, obj);
	to_obj_space(f->v3, &f->v3, obj);
	to_obj_space(f->vn1, &f->vn1, obj);
	to_obj_space(f->vn2, &f->vn2, obj);
	to_obj_space(f->vn3, &f->vn3, obj);
}

int		camera_draw_3dobject(t_3dobject *obj, t_camera *cam, t_env *env)
{
	t_list		*l;
	t_face		f;
	t_point		p;
	t_3dvertex	c_space;
	t_2dpair	c_view;

	l = obj->faces;
	p.c.r = 0;
	p.c.g = 0;
	p.c.b = 255;
	p.c.a = 0;
	while (l)
	{
		f = *(t_face *)l->content;
		face_to_obj_space(&f, obj);
		to_camera_space(&f.v1, &c_space, cam);
		p.z = (c_space.x * c_space.x) + (c_space.y * c_space.y) + (c_space.z * c_space.z);
		camera_project_vertex(&c_space, &c_view, cam);
		p.pos.x = c_view.x;
		p.pos.y = c_view.y;
		camera_draw_point(&p, cam, env);

		to_camera_space(&f.v2, &c_space, cam);
		p.z = (c_space.x * c_space.x) + (c_space.y * c_space.y) + (c_space.z * c_space.z);
		camera_project_vertex(&c_space, &c_view, cam);
		p.pos.x = c_view.x;
		p.pos.y = c_view.y;
		camera_draw_point(&p, cam, env);

		to_camera_space(&f.v3, &c_space, cam);
		p.z = (c_space.x * c_space.x) + (c_space.y * c_space.y) + (c_space.z * c_space.z);
		camera_project_vertex(&c_space, &c_view, cam);
		p.pos.x = c_view.x;
		p.pos.y = c_view.y;
		camera_draw_point(&p, cam, env);

		l = l->next;
	}
	return (1);
}
