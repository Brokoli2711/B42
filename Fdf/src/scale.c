/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:37:48 by elfo              #+#    #+#             */
/*   Updated: 2025/06/04 17:43:47 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void calculate_auto_scale_and_center(t_env *env)
{
        float min_x = INFINITY;
        float max_x = -INFINITY;
        float min_y = INFINITY;
        float max_y = -INFINITY;

        for (int i = 0; i < env->map_w * env->map_h; i++)
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
        float width = max_x - min_x;
        float height = max_y - min_y;
        // Escalat per a que càpiga dins la finestra amb marge
        float scale_x = (WINDOW_WIDTH * 0.9) / width;
        float scale_y = (WINDOW_HEIGHT * 0.9) / height;
        // Tria el més petit per assegurar que càpiga completament
        env->scale = fminf(scale_x, scale_y);
        // Calcular centre de la imatge i de la finestra
        float center_x = (min_x + max_x) / 2.0f;
        float center_y = (min_y + max_y) / 2.0f;
        env->offset_x = WINDOW_WIDTH / 2.0f - center_x * env->scale;
        env->offset_y = WINDOW_HEIGHT / 2.0f - center_y * env->scale;
}

