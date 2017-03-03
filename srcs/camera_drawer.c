#include "camera_drawer.h"

static void	draw_line_X(t_point p, t_line_param *l, t_camera *cam);

static void	draw_line_Y(t_point p, t_line_param *l, t_camera *cam);

t_bool	is_in_camview(t_2ipair pos, t_camera *cam)
{
	if (pos.x < cam->size.x && pos.x >= 0 && pos.y < cam->size.y && pos.y >= 0)
		return (1);
	return (0);
}

int			camera_draw_point(t_point* p, t_camera *cam)
{
	if (p->pos.x < 0 || p->pos.x >= cam->size.x
			|| p->pos.y < 0 || p->pos.y >= cam->size.y)
		return (0);
	if (cam->pixels[p->pos.y][p->pos.x].z_buffer != -1
			&& p->z > cam->pixels[p->pos.y][p->pos.x].z_buffer)
				return (-1);
	cam->pixels[p->pos.y][p->pos.x].color = p->c;
	return (1);
}

void		camera_draw_line(t_point* p1, t_point* p2, t_camera *cam)
{
	t_line_param	l;
	t_point			*p;

	if (!is_in_camview(p1->pos, cam) && !is_in_camview(p2->pos, cam))
		return;
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
		draw_line_X(*p1, &l, cam);
	else
		draw_line_Y(*p1, &l, cam);
}

static void	draw_line_X(t_point p, t_line_param *l, t_camera *cam)
{
	double	cumul;
	int		i;

	l->z = l->z / l->d.x;
	cumul = l->d.x / 2 ;
	i = 0;
	l->color_incr.a /= l->d.x;
	l->color_incr.b /= l->d.x;
	l->color_incr.c /= l->d.x;
	while (++i <= l->d.x)
	{
		p.pos.x += l->incr.x;
		p.z += l->z;
		p.c.r += l->color_incr.a;
		p.c.g += l->color_incr.b;
		p.c.b += l->color_incr.c;
		cumul += l->d.y;
		if (cumul >= l->d.x)
		{
			cumul -= l->d.x;
			p.pos.y += l->incr.y;
		}
		if (!camera_draw_point(&p, cam))
			return;
	}
}

static void	draw_line_Y(t_point p, t_line_param *l, t_camera *cam)
{
	double	cumul;
	int		i;

	l->z = l->z / l->d.y;
	cumul = l->d.y / 2 ;
	i = 1;
	l->color_incr.a /= l->d.y;
	l->color_incr.b /= l->d.y;
	l->color_incr.c /= l->d.y;
	while (++i <= l->d.x)
	{
		p.pos.y += l->incr.y;
		p.z += l->z;
		p.c.r += l->color_incr.a;
		p.c.g += l->color_incr.b;
		p.c.b += l->color_incr.c;
		cumul += l->d.x;
		if (cumul >= l->d.x)
		{
			cumul -= l->d.y;
			p.pos.y += l->incr.x;
		}
		if (!camera_draw_point(&p, cam))
			return;
	}

}

