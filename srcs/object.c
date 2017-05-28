/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 02:03:37 by nboste            #+#    #+#             */
/*   Updated: 2017/05/28 13:55:24 by nboste           ###   ########.fr       */
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

static void		face_to_obj_space(t_face *f, t_3dobject *obj)
{
	to_obj_space(f->v1, &f->v1, obj);
	to_obj_space(f->v2, &f->v2, obj);
	to_obj_space(f->v3, &f->v3, obj);
	//	to_obj_space(f->vn1, &f->vn1, obj);
	//	to_obj_space(f->vn2, &f->vn2, obj);
	//	to_obj_space(f->vn3, &f->vn3, obj);
}

int		camera_draw_3dobject(t_3dobject *obj, t_camera *cam, t_env *env)
{
	t_list		*l;
	t_face		*f;
	t_face		fm;
	t_3dvertex	c1, c2, c3;
	t_2dpair	c_view;
	t_point		p1, p2, p3;
	int i = 1;

	l = obj->faces;
	while (l)
	{
		f = (t_face *)l->content;
		fm = *f;
		f = &fm;
		if (!i){
		face_to_obj_space(f, obj);
		if (to_camera_space(&f->v1, &c1, cam))
		{
			if (to_camera_space(&f->v2, &c2, cam))
			{
				if (to_camera_space(&f->v3, &c3, cam))
				{
					p1.z = (c1.x * c1.x) + (c1.y * c1.y) + (c1.z * c1.z);
					p2.z = (c2.x * c2.x) + (c2.y * c2.y) + (c2.z * c2.z);
					p3.z = (c3.x * c3.x) + (c3.y * c3.y) + (c3.z * c3.z);
					p1.c = f->c1;
					p2.c = f->c2;
					p3.c = f->c3;
					camera_project_vertex(&c1, &c_view, cam);
					p1.pos.x = c_view.x;
					p1.pos.y = c_view.y;
					camera_project_vertex(&c2, &c_view, cam);
					p2.pos.x = c_view.x;
					p2.pos.y = c_view.y;
					camera_project_vertex(&c3, &c_view, cam);
					p3.pos.x = c_view.x;
					p3.pos.y = c_view.y;
					camera_draw_line(&p2, &p1, cam, env);
			//		if (i)
			//		camera_draw_line(&p2, &p3, cam, env);
			//		else
					camera_draw_line(&p1, &p3, cam, env);
				}
			}
		}
		}
		if (i)
			i = 0;
		else
			i = 1;
		l = l->next;
	}
	return (1);
}
