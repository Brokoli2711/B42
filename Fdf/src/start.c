/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egelma-b <egelma-b@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:40:24 by egelma-b          #+#    #+#             */
/*   Updated: 2025/06/08 19:53:10 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <unistd.h>

void	set_and_free_final_tab(t_env *env, char **line_tab)
{
	env->final_tab[env->y][env->x] = ft_atoi(line_tab[env->x]);
	free(line_tab[env->x]);
}

void	parse_map(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**line_tab;

	fd = open(file, O_RDONLY);
	env->final_tab = malloc(env->map_h * sizeof(int *));
	if (!env->final_tab)
		error("Parse malloc failed");
	while (env->y < env->map_h)
	{
		env->final_tab[env->y] = malloc(env->map_w * sizeof(int));
		if (!env->final_tab[env->y])
			error("Malloc failed");
		line = get_next_line(fd);
		line_tab = ft_split(line, ' ');
		free(line);
		env->x = -1;
		while (++env->x < env->map_w)
			set_and_free_final_tab(env, line_tab);
		env->y++;
		free(line_tab);
	}
	close(fd);
}

int	env_init(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		free(env->mlx);
		return (MLX_ERROR);
	}
	env->window = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf");
	if (env->window == NULL)
		return (MLX_ERROR);
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	calculate_auto_scale_and_center(env);
	fill_2d_points(env);
	if(!env->centered)
		center_points(env);
	limits(env);
	h_management(env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	render(t_env *env)
{
	draw_background(env);
	fill_2d_points(env);
	limits(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
	return (0);
}
