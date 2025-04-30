#include "../includes/fdf.h"
#include "math.h"
void	fill_2d_points(t_env *env)
{
	int	i;

	i = 0;
	env->final_points = malloc(env->map_h * env->map_w * sizeof(t_fpoint));
	if (!env->final_points)
		error("Malloc failed");
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
		env->final_points[i].x *= -env->scale;
		env->final_points[i++].y *= env->scale;
	}
}
