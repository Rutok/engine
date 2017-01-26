/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:34:25 by nboste            #+#    #+#             */
/*   Updated: 2017/01/24 23:53:34 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "libft.h"
#include "error.h"
#include <math.h>

t_matrix	*get_matrix_rotation_x(double rad)
{
	int			i;
	double		**rotmat;
	t_matrix	*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix)))
		|| !(rotmat = (double **)malloc(sizeof(double *) * 3)))
		ft_exit(MSG_MALLOC);
	i = 0;
	while (i < 3)
		if (!(rotmat[i++] = (double*)malloc(sizeof(double) * 3)))
			ft_exit(MSG_MALLOC);
	rotmat[0][0] = 1;
	rotmat[0][1] = 0;
	rotmat[0][2] = 0;
	rotmat[1][0] = 0;
	rotmat[1][1] = cos(rad);
	rotmat[1][2] = sin(rad);
	rotmat[2][0] = 0;
	rotmat[2][1] = -sin(rad);
	rotmat[2][2] = cos(rad);
	matrix->tab = rotmat;
	return (matrix);
}

t_matrix	*get_matrix_rotation_y(double rad)
{
	int			i;
	double		**rotmat;
	t_matrix	*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix)))
		|| !(rotmat = (double **)malloc(sizeof(double *) * 3)))
		ft_exit(MSG_MALLOC);
	i = 0;
	while (i < 3)
		if (!(rotmat[i++] = (double*)malloc(sizeof(double) * 3)))
			ft_exit(MSG_MALLOC);
	rotmat[0][0] = cos(rad);
	rotmat[0][1] = 0;
	rotmat[0][2] = -sin(rad);
	rotmat[1][0] = 0;
	rotmat[1][1] = 1;
	rotmat[1][2] = 0;
	rotmat[2][0] = sin(rad);
	rotmat[2][1] = 0;
	rotmat[2][2] = cos(rad);
	matrix->tab = rotmat;
	return (matrix);
}

t_matrix	*get_matrix_rotation_z(double rad)
{
	int			i;
	double		**rotmat;
	t_matrix	*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix)))
		|| !(rotmat = (double **)malloc(sizeof(double *) * 3)))
		ft_exit(MSG_MALLOC);
	i = 0;
	while (i < 3)
		if (!(rotmat[i++] = (double*)malloc(sizeof(double) * 3)))
			ft_exit(MSG_MALLOC);
	rotmat[0][0] = cos(rad);
	rotmat[0][1] = sin(rad);
	rotmat[0][2] = 0;
	rotmat[1][0] = -sin(rad);
	rotmat[1][1] = cos(rad);
	rotmat[1][2] = 0;
	rotmat[2][0] = 0;
	rotmat[2][1] = 0;
	rotmat[2][2] = 1;
	matrix->tab = rotmat;
	return (matrix);
}

t_matrix	*get_matrix_homothety(double k)
{
	int			i;
	double		**homo;
	t_matrix	*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix)))
		|| !(homo = (double **)malloc(sizeof(double *) * 3)))
		ft_exit(MSG_MALLOC);
	i = 0;
	while (i < 3)
		if (!(homo[i++] = (double*)malloc(sizeof(double) * 3)))
			ft_exit(MSG_MALLOC);
	homo[0][0] = k;
	homo[0][1] = 0;
	homo[0][2] = 0;
	homo[1][0] = 0;
	homo[1][1] = k;
	homo[1][2] = 0;
	homo[2][0] = 0;
	homo[2][1] = 0;
	homo[2][2] = k;
	matrix->tab = homo;
	return (matrix);
}
