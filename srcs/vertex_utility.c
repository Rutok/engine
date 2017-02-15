/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:57:41 by nboste            #+#    #+#             */
/*   Updated: 2017/02/15 23:13:16 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex_utility.h"

void	rotate_3dvertex(t_3dvertex *v, t_3dvertex n, double angle)
{
	t_3dvertex	tmp;
	t_2dpair	trig;

	if (!angle)
		return;
	trig.x = cos(angle);
	trig.y = sin(angle);
	tmp.x = ((trig.x + ((1 - trig.x) * n.x * n.x)) * v->x)
		+ ((((1 - trig.x) * n.x * n.y) - (trig.y * n.z)) * v->y)
		+ ((((1 - trig.x) * n.x * n.z) + (trig.y * n.y)) * v->z);
	tmp.y = ((((1 - trig.x) * n.x * n.y) + (trig.y * n.z)) * v->x)
		+ ((trig.x + ((1 - trig.x) * n.y * n.y)) * v->y)
		+ ((((1 - trig.x) * n.y * n.z) - (trig.y * n.x)) * v->z);
	tmp.z = ((((1 - trig.x) * n.x * n.z) - (trig.y * n.y)) * v->x)
		+ ((((1 - trig.x) * n.y * n.z) + (trig.y * n.x)) * v->y)
		+ ((trig.x + ((1 - trig.x) * n.z * n.z)) * v->z);
	*v = tmp;

}

void	translate_3dvertex(t_3dvertex *v, t_3dvertex t)
{
	v->x += t.x;
	v->y += t.y;
	v->z += t.z;
}

void	scale_3dvertex(t_3dvertex *v, double k)
{
	v->x *= k;
	v->y *= k;
	v->z *= k;
}
