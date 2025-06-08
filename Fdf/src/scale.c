/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:37:48 by elfo              #+#    #+#             */
/*   Updated: 2025/06/08 19:55:07 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void calculate_auto_scale_and_center(t_env *env)
{
    float   min_x;
    float   min_y;
    float   max_x;
    float   max_y;
    float   x;
    float   y;
    int     i;

    min_x = INFINITY;
    max_x = -INFINITY;
    min_y = INFINITY;
    max_y = -INFINITY;
    i = -1;
    while (++i < env->map_h * env->map_w)
    {
        x = env->initial_points[i].x * sinf(env->alpha) +
            env->initial_points[i].y * sinf(env->alpha + 2) +
            env->initial_points[i].z * env->altitude * sinf(env->alpha - 2);

        y = env->initial_points[i].y * cosf(env->alpha) +
            env->initial_points[i].y * cosf(env->alpha + 2) +
            env->initial_points[i].z * env->altitude * cosf(env->alpha - 2);

        if (x < min_x) min_x = x;
        if (x > max_x) max_x = x;
        if (y < min_y) min_y = y;
        if (y > max_y) max_y = y;
    }
    env->scale = fminf((WINDOW_WIDTH * 0.9f) / (max_x - min_x), (WINDOW_HEIGHT * 0.9f) / (max_y - min_y));
}
