/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/10/31 14:53:18 by brolivei         ###   ########.fr       */
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
#include "../minilibx-linux/mlx.h"

typedef	struct e_FPS
{
	double	time;
	double	oldTime;
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
}				t_rayCast;

typedef	struct e_main
{
	void	*mlx;
	void	*mlx_win;
}				t_main;



#endif
