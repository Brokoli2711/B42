#include "../includes/fdf.h"

int	error(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	env.alpha = 7.37;
	env.translation = 1;
	env.scale = 30;
	env.altitude = 1;
	env.y = 0;
	env.map_h = 0;
	env.map_w = 0;
	env.path_map = argv[1];

	if (argc == 2)
	{
		map_info(&env, env.path_map);
		check_format(&env, env.path_map);
		parse_map(&env, env.path_map);
		fill_3d_points(&env);
		env_init(&env);
	}
	else
		error("2 argumens needed");
	while (1)
		;
}

void	free_final_tab(t_env *env)
{
	int	y;

	y = 0;
	while (y < env->map_h)
	{
		free(env->final_tab[y]);
		y++;
	}
	free(env->final_tab);
}
