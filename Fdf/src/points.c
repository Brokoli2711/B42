/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:39:41 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/10 15:31:04 by egelma-b         ###   ########.fr       */
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
				env->final_tab[env->y][env->x].z,
				RED};
			i++;
			env->x++;
		}
		env->y++;
	}
}

void	center_points(t_env *env)
{
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	int		i;

	i = 0;
	min_x = env->final_points[0].x;
	max_x = env->final_points[0].x;
	min_y = env->final_points[0].y;
	max_y = env->final_points[0].y;
	while (++i < env->map_h * env->map_w)
	{
		if (env->final_points[i].x < min_x)
			min_x = env->final_points[i].x;
		if (env->final_points[i].x > max_x)
			max_x = env->final_points[i].x;
		if (env->final_points[i].y < min_y)
			min_y = env->final_points[i].y;
		if (env->final_points[i].y > max_y)
			max_y = env->final_points[i].y;
	}
	env->translation_x = WINDOW_WIDTH / 2.0f - ((min_x + max_x) / 2.0f);
	env->translation_y = WINDOW_HEIGHT / 2.0f - ((min_y + max_y) / 2.0f);
	env->centered = true;
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
		env->final_points[i].y = env->initial_points[i].y \
				* cosf(env->alpha) + env->initial_points[i].y \
				* cosf(env->alpha + 2) \
				+ (env->initial_points[i].z * env->altitude) \
				* cosf(env->alpha - 2);
		env->final_points[i].x = env->initial_points[i].x \
				* sinf(env->alpha) + env->initial_points[i].y \
				* sinf(env->alpha + 2) \
				+ (env->initial_points[i].z * env->altitude) \
				* sinf(env->alpha - 2);
		env->final_points[i].x *= env->scale;
		env->final_points[i++].y *= -env->scale;
	}
}
