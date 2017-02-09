/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:10:29 by nboste            #+#    #+#             */
/*   Updated: 2017/02/08 23:16:34 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "types.h"

void		init_camera(t_env *env, double v_field, t_camera *camera);

t_2dpair	camera_project_vertex(t_3dvertex *v, t_camera *camera);

void		to_camera_space(t_3dvertex* v, t_camera *camera);

void		reset_camera_pixels(t_camera *camera);

#endif
