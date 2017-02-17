/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 14:00:35 by nboste            #+#    #+#             */
/*   Updated: 2017/02/17 22:06:18 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include "error.h"
#include "drawer.h"
#include "SDL2/SDL_thread.h"

static void	print_fps(void)
{
	static int time;
	static int fps;
	Uint32			t;

	fps++;
	if (!time)
		time = SDL_GetTicks();
	if ((t = SDL_GetTicks()) >= (Uint32)time + 500)
	{
		ft_putstr("FPS : ");
		ft_putnbr(fps+ fps);
		ft_putchar('\n');
		fps = 0;
		time = t;
	}
}

void	engine_init(t_env *env, void (*init)(t_env *), int (*process)(void *), void (*destroy)(t_env *))
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_exit(MSG_SDL_INIT_FAILED);
	if (!(env->win.win_sdl = SDL_CreateWindow(env->win.name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, env->win.size.x, env->win.size.y, SDL_WINDOW_SHOWN)))
		ft_exit(MSG_SDL_INIT_FAILED);
	SDL_SetWindowFullscreen(env->win.win_sdl, SDL_WINDOW_FULLSCREEN);
	drawer_init(env);
	env->app.init = init;
	env->app.process = process;
	env->app.destroy = destroy;
	env->app.init(env);
}

int		engine_run(t_env *env)
{
//	int	time;
//	int	etime;
//	int	fps;

//	fps = 1000 / FPS;
	event_reset(&env->event);
	env->event.in_use = 0;
//	etime = 0;
//	time = SDL_GetTicks();
//	env->thread = SDL_CreateThread(env->app.process, "app_thread", env);
		print_fps();
	while (!env->event.exit)
	{
//		etime = SDL_GetTicks() - time;
//		if (etime < fps)
//			SDL_Delay(fps - etime);
//		time += etime;
		event_process(&env->event);
		env->app.process(env);
		if (env->rend.draw)
			drawer_process(&env->rend);
	}
//	SDL_WaitThread(env->thread, &time);
	engine_destroy(env);
	return (0);
}

void	engine_destroy(t_env *env)
{
	if (env->app.destroy)
		env->app.destroy(env);
	drawer_destroy(&env->rend);
	SDL_DestroyWindow(env->win.win_sdl);
	SDL_Quit();
}
