/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_drawer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:21:50 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 13:42:07 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_drawer.h"
#include "color.h"

static void	draw_line_x(t_point p, t_line_param *l, t_camera *cam, t_env *env)
{
	double		cumul;
	int			i;
	t_3dtriplet	c;

	l->z = l->z / l->d.x;
	cumul = l->d.x / 2.0;
	i = 0;
	color_setup_x(&c, l, &p);
	while (++i <= l->d.x)
	{
		p.pos.x += l->incr.x;
		p.z += l->z;
		color_increment(&c, l, &p);
		cumul += l->d.y;
		if (cumul >= l->d.x)
		{
			cumul -= l->d.x;
			p.pos.y += l->incr.y;
		}
		if (!camera_draw_point(&p, cam, env))
			return ;
	}
}

static void	draw_line_y(t_point p, t_line_param *l, t_camera *cam, t_env *env)
{
	double		cumul;
	int			i;
	t_3dtriplet	c;

	l->z = l->z / l->d.y;
	cumul = l->d.y / 2.0;
	i = 0;
	color_setup_y(&c, l, &p);
	while (++i <= l->d.y)
	{
		p.pos.y += l->incr.y;
		p.z += l->z;
		color_increment(&c, l, &p);
		cumul += l->d.x;
		if (cumul >= l->d.y)
		{
			cumul -= l->d.y;
			p.pos.x += l->incr.x;
		}
		if (!camera_draw_point(&p, cam, env))
			return ;
	}
}

t_bool		is_in_camview(t_2ipair pos, t_camera *cam)
{
	if (pos.x < cam->size.x && pos.x >= 0 && pos.y < cam->size.y && pos.y >= 0)
		return (1);
	return (0);
}

int			camera_draw_point(t_point *p, t_camera *c, t_env *env)
{
	if (p->pos.x < 0 || p->pos.x >= c->size.x
			|| p->pos.y < 0 || p->pos.y >= c->size.y)
		return (0);
	if (c->z_buffer[p->pos.y * c->size.x + p->pos.x]
			&& p->z > c->z_buffer[p->pos.y * c->size.x + p->pos.x])
		return (-1);
	env->rend.pixels[p->pos.x + c->size.x * p->pos.y] = t_colortouint32(p->c);
	c->z_buffer[p->pos.y * c->size.x + p->pos.x] = p->z;
	return (1);
}

void		camera_draw_line(t_point *p1, t_point *p2, t_camera *cam, t_env *e)
{
	t_line_param	l;
	t_point			*p;

	if (!is_in_camview(p1->pos, cam) && !is_in_camview(p2->pos, cam))
		return ;
	if (!is_in_camview(p1->pos, cam))
	{
		p = p2;
		p2 = p1;
		p1 = p;
	}
	l.d.x = p2->pos.x - p1->pos.x;
	l.d.y = p2->pos.y - p1->pos.y;
	l.incr.x = (l.d.x > 0) ? 1 : -1;
	l.incr.y = (l.d.y > 0) ? 1 : -1;
	l.d.x = abs(l.d.x);
	l.d.y = abs(l.d.y);
	l.z = p2->z - p1->z;
	l.color_incr.a = p2->c.r - p1->c.r;
	l.color_incr.b = p2->c.g - p1->c.g;
	l.color_incr.c = p2->c.b - p1->c.b;
	if (l.d.x > l.d.y)
		draw_line_x(*p1, &l, cam, e);
	else if (l.d.y)
		draw_line_y(*p1, &l, cam, e);
}
