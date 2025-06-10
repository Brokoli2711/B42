/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:37:20 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/10 13:27:30 by egelma-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(t_env *env, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = env->addr + (y * env->line_length + \
			x * (env->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1, int color)
{
	float	step;
	float	x;
	float	y;
	int		i;
	t_delta	delta;

	i = 0;
	delta.dx = point1.x - point0.x;
	delta.dy = point1.y - point0.y;
	if (fabsf(delta.dx) >= fabsf(delta.dy))
		step = fabsf(delta.dx);
	else
		step = fabsf(delta.dy);
	delta.dx = delta.dx / step;
	delta.dy = delta.dy / step;
	x = point0.x;
	y = point0.y;
	while (i++ < step)
	{
		put_pixel(env, roundf(env->translation_x + x),
			roundf(env->translation_y + y), color);
		x += delta.dx;
		y += delta.dy;
	}
}

void	draw_background(t_env *env)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h <= WINDOW_HEIGHT)
	{
		w = 0;
		while (w <= WINDOW_WIDTH)
			put_pixel(env, w++, h, BLACK);
		h++;
	}
}
