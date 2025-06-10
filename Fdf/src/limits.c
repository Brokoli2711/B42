/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:42:56 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/09 22:50:32 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

static void	set_right_limit(t_env *env)
{
	env->actual_x = 1;
	if (env->actual_y == env->map_h)
	{
		while (env->actual_x != env->map_w)
		{
			right_limit(env);
			env->actual_x++;
			env->i++;
		}
	}
}

void	limits(t_env *env)
{
	env->actual_y = 1;
	env->i = 0;
	while (env->actual_y != env->map_h)
	{
		env->actual_x = 1;
		while (env->actual_x < env->map_w)
		{
			no_limit(env);
			env->actual_x++;
			env->i++;
		}
		if (env->actual_x == env->map_w)
		{
			down_limit(env);
			env->actual_x++;
			env->i++;
		}
		env->actual_y++;
	}
	set_right_limit(env);
	free(env->final_points);
}

void	no_limit(t_env *env)
{
	right_limit(env);
	down_limit(env);
}

void	right_limit(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	int		color;

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + 1].x;
	y1 = env->final_points[env->i + 1].y;
	color = env->final_tab[env->i / env->map_w][env->i % env->map_w].color;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1}, color);
}

void	down_limit(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	int		color;

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + env->map_w].x;
	y1 = env->final_points[env->i + env->map_w].y;
	color = env->final_tab[env->i / env->map_w][env->i % env->map_w].color;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1}, color);
}
