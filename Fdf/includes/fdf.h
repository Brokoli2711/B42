#ifndef FDF_H
# define FDF_H
# include "../mlx_linux/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR 1
# define ZOOM_FACTOR 1.1
# define TRANS_X 7
# define TRANS_Y 2
# define ALTITUDE 0.04

# define RED 0x00FF0000
# define BLACK 0x00000000

typedef struct s_ipoint
{
	int	x;
	int	y;
	int	z;
}	t_ipoint;

typedef struct s_fpoint
{
	float	x;
	float	y;
}	t_fpoint;

typedef struct s_delta
{
	float	dx;
	float	dy;
}	t_delta;

typedef struct s_env
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*addr;
	char		*path_map;
	int			**final_tab;
	int			map_w;
	int			map_h;
	int			x;
	int			y;
	int			i;
	int			actual_x;
	int			actual_y;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			scale;
	int			translation;
	float		altitude;
	float		zoom;
	float		alpha;
	t_ipoint	*initial_points;
	t_fpoint	*final_points;
	t_delta		*delta;
}	t_env;

//FDF.C
int	error(char *message);
void	free_final_tab(t_env *env);

//START.C
void	map_info(t_env *env, char *file);
void	check_format(t_env *env, char *file);
void	parse_map(t_env *env, char *file);
int	env_init(t_env *env);
int	render(t_env *env);

//POINTS.C
void	fill_2d_points(t_env *env);
void	fill_3d_points(t_env *env);

//LIMITS.C
void	limits(t_env *env);
void	no_limit(t_env *env);
void	right_limit(t_env *env);
void	down_limit(t_env *env);

//DRAW.C
void	put_pixel(t_env *env, int x, int y, int color);
void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1);
void	draw_background(t_env *env);

//HOOKS.C
void	h_management(t_env *env);
int	key_handler(int key, t_env *env);
int	close_win(t_env *env);
int	mouse_handler(int mousecode, int x, int y, t_env *env);
#endif
