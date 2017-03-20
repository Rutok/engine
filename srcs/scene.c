/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 02:19:30 by nboste            #+#    #+#             */
/*   Updated: 2017/03/20 16:35:23 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "camera_drawer.h"

void	draw_scene(t_scene *scene, t_env *env)
{
	t_list	*l;

	l = scene->objects;
	while (l)
	{
		camera_draw_3dobject((t_3dobject *)(l->content), &scene->camera, env);
		l = l->next;
	}
}
