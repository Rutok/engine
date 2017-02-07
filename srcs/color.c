/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 00:47:25 by nboste            #+#    #+#             */
/*   Updated: 2017/02/07 01:15:30 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

uint32	t_colortouint32(t_color* c)
{
	uint32	u;

	u = c->r;
	u <<= 8;
	u += c->g;
	u <<= 8;
	u += c->b;
	u <<= 8;
	u += c->a;
	return (u);
}
