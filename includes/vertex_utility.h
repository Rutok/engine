/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_utility.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:57:13 by nboste            #+#    #+#             */
/*   Updated: 2017/02/15 23:11:46 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_UTILITY_H
# define VERTEX_UTILITY_H

# include "types.h"

/*
 * Rotate the v vertex around the axis by the angle given (rad)
*/
void	rotate_3dvertex(t_3dvertex *v, t_3dvertex axis, double angle);

void	translate_3dvertex(t_3dvertex *v, t_3dvertex t);

void	scale_3dvertex(t_3dvertex *v, double k);

#endif
