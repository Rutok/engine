/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_drawer_utility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:30:01 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 13:41:45 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_drawer.h"
#include "color.h"
#include <math.h>

void	color_increment(t_3dtriplet *c, t_line_param *l, t_point *p)
{
	c->a += l->color_incr.a;
	c->b += l->color_incr.b;
	c->c += l->color_incr.c;
	p->c.r = round(c->a);
	p->c.g = round(c->b);
	p->c.b = round(c->c);
}

void	color_setup_x(t_3dtriplet *c, t_line_param *l, t_point *p)
{
	l->color_incr.a /= l->d.x;
	l->color_incr.b /= l->d.x;
	l->color_incr.c /= l->d.x;
	c->a = p->c.r;
	c->b = p->c.g;
	c->c = p->c.b;
}

void	color_setup_y(t_3dtriplet *c, t_line_param *l, t_point *p)
{
	l->color_incr.a /= l->d.y;
	l->color_incr.b /= l->d.y;
	l->color_incr.c /= l->d.y;
	c->a = p->c.r;
	c->b = p->c.g;
	c->c = p->c.b;
}
