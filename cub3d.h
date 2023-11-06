/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/06 14:31:31 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "../minilibx-linux/mlx.h"

typedef	struct e_FPS
{
	clock_t	frameStart;
	clock_t	frameEnd;
	double	frameTime;
	double	fps;
	char	fpsString[30];
}				t_FPS;

typedef	struct e_rayCast
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
}				t_rayCast;

typedef	struct e_move
{
	double	moveSpeed;
	double	rotSpeed;
}				t_move;


typedef	struct e_main
{
	void		*mlx;
	void		*mlx_win;
	t_rayCast	*rayCast;
	t_FPS		*fps;
	t_move		*move;
}				t_main;

void	rayCasting(t_main *main, int worldMap[mapWidth][mapHeight]);

void	ft_events(t_main *main);

#endif
