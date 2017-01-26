/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:18:25 by nboste            #+#    #+#             */
/*   Updated: 2017/01/24 23:49:19 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct	s_matrix
{
	double	**tab;
}				t_matrix;

t_matrix	*get_matrix_rotation_x(double rad);

t_matrix	*get_matrix_rotation_y(double rad);

t_matrix	*get_matrix_rotation_z(double rad);

t_matrix	*get_matrix_homothety(double fac);

#endif
