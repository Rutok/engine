/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 02:19:30 by nboste            #+#    #+#             */
/*   Updated: 2017/01/26 04:00:56 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	draw_scene(t_scene *scene)
{
	t_list	*l;

	l = scene->objects;
	while (l)
	{
		((t_object *)(l->content))->draw_obj(scene, (t_object *)(l->content));
		l = l->next;
	}
}
