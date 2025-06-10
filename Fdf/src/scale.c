/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:57:21 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/10 15:20:54 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void	set_min_max(float *min, float *max, float x, float y)
{
	if (x < min[0])
		min[0] = x;
	if (y < min[1])
		min[1] = y;
	if (x > max[0])
		max[0] = x;
	if (y > max[1])
		max[1] = y;
}

void	calculate_auto_scale_and_center(t_env *env)
{
	float	min[2];
	float	max[2];
	float	x;
	float	y;
	int		i;

	min[0] = INFINITY;
	min[1] = INFINITY;
	max[0] = -INFINITY;
	max[1] = -INFINITY;
	i = -1;
	while (++i < env->map_h * env->map_w)
	{
		x = env->initial_points[i].x * sinf(env->alpha)
			+ env->initial_points[i].y * sinf(env->alpha + 2)
			+ env->initial_points[i].z * env->altitude * sinf(env->alpha - 2);
		y = env->initial_points[i].y * cosf(env->alpha)
			+ env->initial_points[i].y * cosf(env->alpha + 2)
			+ env->initial_points[i].z * env->altitude * cosf(env->alpha - 2);
		set_min_max(min, max, x, y);
	}
	env->scale = fminf((WINDOW_WIDTH * 0.9f) / (max[0] - min[0]),
			(WINDOW_HEIGHT * 0.9f) / (max[1] - min[1]));
}
