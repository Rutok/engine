/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 14:00:13 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 17:06:18 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "types.h"
# include "event.h"

# define FPS 120

void	engine_init(t_env *env, void (*init)(t_env *),
						int (*process)(void *), void (*destroy)(t_env *));

int		engine_run(t_env *env);

void	engine_destroy(t_env *env);

#endif
