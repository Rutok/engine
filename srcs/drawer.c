/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 06:01:31 by nboste            #+#    #+#             */
/*   Updated: 2017/05/29 17:04:21 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "libft.h"
#include "error.h"
#include "color.h"

void	drawer_init(t_env *env)
{
	if (!(env->rend.rend_sdl = SDL_CreateRenderer(env->win.win_sdl, -1, SDL_RENDERER_ACCELERATED)))
		ft_exit(MSG_SDL_INIT_FAILED);
	if (!(env->rend.texture_sdl = SDL_CreateTexture(env->rend.rend_sdl, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, env->win.size.x, env->win.size.y)))
		ft_exit(MSG_SDL_INIT_FAILED);
	if (!(env->rend.pixels = (t_uint32 *)malloc(sizeof(t_uint32) * env->win.size.x * env->win.size.y)))
		ft_exit(MSG_MALLOC);
	env->rend.size.x = env->win.size.x;
	env->rend.size.y = env->win.size.y;
}

void	drawer_process(t_renderer *rend)
{
	SDL_UpdateTexture(rend->texture_sdl, NULL, rend->pixels, rend->size.x * sizeof(t_uint32));
	SDL_RenderCopy(rend->rend_sdl, rend->texture_sdl, NULL, NULL);
	SDL_RenderPresent(rend->rend_sdl);
	drawer_clean(rend);
	rend->draw = 0;
}

void	drawer_destroy(t_renderer *rend)
{
	free(rend->pixels);
	SDL_DestroyRenderer(rend->rend_sdl);
	SDL_DestroyTexture(rend->texture_sdl);
}

void	drawer_put_pixel(t_2ipair coord, t_uint32 color, t_renderer *rend)
{
	rend->pixels[coord.x + rend->size.x * coord.y] = color;
}

void	drawer_clean(t_renderer *rend)
{
	ft_memset(rend->pixels, 0, sizeof(int) * rend->size.x * rend->size.y);
}

void	drawer_wait_copy(t_env *env, t_camera *cam)
{
	ft_memset(cam->z_buffer, 0, sizeof(t_uint32) * cam->size.x * cam->size.y);
	env->rend.draw = 1;
}
