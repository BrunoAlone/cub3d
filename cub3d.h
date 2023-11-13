/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/13 12:12:23 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define W 119
#define S 115
#define D 100
#define A 97
#define RIGHT 65363
#define LEFT 65361
#define ESC 65307

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "../minilibx-linux/mlx.h"

typedef	struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}				t_image;

typedef	struct s_rayCast
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	oldDirX;
	double	oldPlaneX;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	double	wallX;
	t_image	*tex;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
}				t_rayCast;

typedef	struct s_main
{
	void		*mlx;
	void		*mlx_win;
	int			worldMap[mapWidth][mapHeight];
	char		**paths;
	t_rayCast	*rayCast;
	t_image		*img;
	t_image		*n_tex;
	t_image		*s_tex;
	t_image		*w_tex;
	t_image		*e_tex;
}				t_main;

void	rayCasting(t_main *main, int worldMap[mapWidth][mapHeight]);

void	ft_events(t_main *main);

void	initialize_mlx(t_main *main);

void	ft_moveForward(t_main *main, int worldMap[mapWidth][mapHeight]);

void	ft_moveBackwards(t_main *main);

void	ft_moveLeft(t_main *main);

void	ft_moveRight(t_main *main);

void	ft_rotate_right(t_main *main);

void	ft_rotate_left(t_main *main);

void	new_image(t_main *main);

//		UTILS

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

#endif
