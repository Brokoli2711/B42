#include "../includes/fdf.h"

void	limits(t_env *env)
{
	env->actual_y = 1;
	env->i = 0;
	while (env->actual_y != env->map_w)
	{
		env->actual_x = 1;
		while (env->actual_x < env->map_w)
			no_limit(env);
		if (env->actual_x == env->map_w)
		{
			down_limit(env);
			env->i++;
		}
		env->actual_y++;
	}
	if (env->actual_y == env->map_h)
	{
		while (env->actual_x != env->map_w)
		{
			right_limit(env);
			env->i++;
		}
	}
	free(env->final_points);
}

void	no_limit(t_env *env)
{
	right_limit(env);
	down_limit(env);
	env->i++;
}

void	right_limit(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + 1].x;
	y1 = env->final_points[env->i + 1].y;
	env->actual_x++;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1});
}

void	down_limit(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + env->map_w].x;
	y1 = env->final_points[env->i + env->map_w].y;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1});
}
