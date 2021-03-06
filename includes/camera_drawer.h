/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_drawer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:59:03 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 13:41:51 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_DRAWER_H
# define CAMERA_DRAWER_H

# include "types.h"
# include "camera.h"

typedef struct	s_line_param
{
	t_2ipair	d;
	t_2ipair	incr;
	double		z;
	t_3dtriplet	color_incr;
}				t_line_param;

int				camera_draw_point(t_point *p, t_camera *cam, t_env *env);

void			camera_draw_line(t_point *p1, t_point *p2,
									t_camera *c, t_env *e);

int				camera_draw_3dobject(t_3dobject *obj, t_camera *cam, t_env *e);

t_bool			is_in_camview(t_2ipair pos, t_camera *cam);

void			color_increment(t_3dtriplet *c, t_line_param *l, t_point *p);

void			color_setup_x(t_3dtriplet *c, t_line_param *l, t_point *p);

void			color_setup_y(t_3dtriplet *c, t_line_param *l, t_point *p);

#endif
