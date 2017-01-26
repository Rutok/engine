/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 00:14:42 by nboste            #+#    #+#             */
/*   Updated: 2017/01/25 00:18:15 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_utility.h"

void	apply_matrix(t_matrix *matrix, t_3dvertex *vertex)
{
	vertex->x = matrix->tab[0][0] * vertex->x
		+ matrix->tab[0][1] * vertex->y
		+ matrix->tab[0][2] * vertex->z;
	vertex->y = matrix->tab[1][0] * vertex->x
		+ matrix->tab[1][1] * vertex->y
		+ matrix->tab[1][2] * vertex->z;
	vertex->z = matrix->tab[2][0] * vertex->x
		+ matrix->tab[2][1] * vertex->y
		+ matrix->tab[2][2] * vertex->z;
}
