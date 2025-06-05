/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:39:41 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/04 20:23:00 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_3d_points(t_env *env)
{
	int	i;

	i = 0;
	env->initial_points = malloc(env->map_h * env->map_w * (sizeof(t_ipoint)));
	if (!env->initial_points)
		error("Malloc failed");
	env->y = 0;
	while (env->y < env->map_h)
	{
		env->x = 0;
		while (env->x < env->map_w)
		{
			env->initial_points[i] = (t_ipoint){env->x, env->y,
				env->final_tab[env->y][env->x]};
			i++;
			env->x++;
		}
		env->y++;
	}
	free_final_tab(env);
}

void	fill_2d_points(t_env *env)
{
	int	i;

	i = 0;
	env->final_points = malloc(env->map_h * env->map_w * sizeof(t_fpoint));
	if (!env->final_points)
	{
		error("Malloc failed");
	}
	while (i < (env->map_w * env->map_h))
	{
		env->final_points[i].x = (env->initial_points[i].x - env->initial_points[i].y) * cosf(env->alpha);
		env->final_points[i].y = (env->initial_points[i].x + env->initial_points[i].y) * sinf(env->alpha) - env->initial_points[i].z * env->altitude;

		/*env->final_points[i].y = env->initial_points[i].y
			* cosf(env->alpha) + env->initial_points[i].y
			* cosf(env->alpha + 2)
			+ (env->initial_points[i].z * env->altitude)
			* cosf(env->alpha - 2);
		env->final_points[i].x = env->initial_points[i].x
			* sinf(env->alpha) + env->initial_points[i].y
			* sinf(env->alpha + 2)
			+ (env->initial_points[i].z * env->altitude)
			* sinf(env->alpha - 2);*/
		env->final_points[i].x *= -1;
		env->final_points[i].x = env->final_points[i].x * env->scale + env->offset_x;
		env->final_points[i].y = env->final_points[i].y * env->scale + env->offset_y;
		i++;
	}
}
