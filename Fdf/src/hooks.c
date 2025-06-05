/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:38:31 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/04 17:49:13 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	h_management(t_env *env)
{
	mlx_hook(env->window, 17, 0, close_win, env);
	mlx_hook(env->window, 4, 0, mouse_handler, env);
	mlx_hook(env->window, 2, 1L << 0, key_handler, env);
}

int	key_handler(int key, t_env *env)
{
	if (key == 65307)
	{
		close_win(env);
		printf("hola");
	}
	else if (key == 13 || key == 97)
		env->translation -= TRANS_X;
	else if (key == 1 || key == 100)
		env->translation += TRANS_X;
	else if (key == 0 || key == 119)
		env->alpha += 0.01;
	else if (key == 2 || key == 115)
		env->alpha -= 0.01;
	else if (key == 65362)
		env->altitude += ALTITUDE;
	else if (key == 65364)
		env->altitude -= ALTITUDE;
	else if (key == 4)
		env->scale *= ZOOM_FACTOR;
	else if (key == 5)
		env->scale *= ZOOM_FACTOR;
	return (0);
}

int	close_win(t_env *env)
{
	if (!env)
		exit (0);
	if (env->initial_points)
		free(env->initial_points);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->window)
		mlx_destroy_window(env->mlx, env->window);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	exit (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	(void) x;
	(void) y;
	if (mousecode == 4)
		env->scale *= ZOOM_FACTOR;
	else if (mousecode == 5)
		env->scale /= ZOOM_FACTOR;
	return (0);
}
