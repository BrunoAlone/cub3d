/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/17 13:35:26 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
//# define SCREEN_WIDTH 1280
//# define SCREEN_HEIGHT 960
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define W 119
# define S 115
# define D 100
# define A 97
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}				t_image;

typedef struct s_f_c
{
	unsigned int	floor;
	unsigned int	ceiling;
}				t_f_c;

typedef struct s_rayCast
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	olddir_x;
	double	oldplane_x;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		drawstart;
	int		drawend;
	int		color;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
}				t_rayCast;

typedef struct s_main
{
	void		*mlx;
	void		*mlx_win;
	int			world_map[MAP_WIDTH][MAP_HEIGHT];
	char		**paths;
	t_rayCast	*raycast;
	t_image		*img;
	t_image		*tex;
	t_image		*n_tex;
	t_image		*s_tex;
	t_image		*w_tex;
	t_image		*e_tex;
	t_image		*door;
	t_f_c		*f_c;
}				t_main;

// Initialization

void	ft_initvar(t_main *main, int worldMap[MAP_WIDTH][MAP_HEIGHT]);

// RayCasting

void	ray_first_steps(t_main *main, int x);

void	ray_seconds_steps(t_main *main);

// MLX

void	my_mlx_pixel_put(t_image *imagem, int x, int y, int color);

// TEX

void	get_wall_x(t_main *main);

void	ft_tex_projection_x(t_main *main);

void	ft_tex_projection_y(t_main *main);

void	ray_casting(t_main *main);

void	ft_events(t_main *main);

void	initialize_mlx(t_main *main);

void	ft_move_forward(t_main *main, int worldMap[MAP_WIDTH][MAP_HEIGHT]);

void	ft_move_backwards(t_main *main);

void	ft_move_left(t_main *main);

void	ft_move_right(t_main *main);

void	ft_rotate_right(t_main *main);

void	ft_rotate_left(t_main *main);

void	new_image(t_main *main);

//		UTILS

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

void	ft_matrix_copy(int world_map[MAP_WIDTH][MAP_HEIGHT], t_main *main);

// MiniMap

void	draw_minimap(t_main *main);

#endif
