/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:44 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/02 15:54:08 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_initVar(t_rayCast *rayCast, t_FPS *fps)
{
	rayCast->posX = 22; // x start position
	rayCast->posY = 12; // y start position
	rayCast->dirX = -1; // Initial direction position x
	rayCast->dirY = 0; // Intitial direction position y
	rayCast->planeX = 0;
	rayCast->planeY = 0.66;
	rayCast->hit = 0;
	fps->time = 0; // Time current frame
	fps->oldTime = 0; // Time of previous frame
}

int	main()
{
	t_rayCast	*rayCast;
	t_FPS		*fps;
	t_main		*main;

	rayCast = malloc(sizeof(t_rayCast));
	fps = malloc(sizeof(t_FPS));
	main = malloc(sizeof(t_main));
	ft_initVar(rayCast, fps);
	main->mlx = mlx_init();
	main->mlx_win = mlx_new_window(main->mlx, screenWidth, screenHeight, "cub3d");

	for (int x = 0; x < screenWidth; x++)
	{
		// Calculate ray position and direction
		rayCast->cameraX = 2 * x / (double)screenWidth - 1; // x - coordinate in camera space
		// Dar cast em (double)screenWidth garante que a operacao e feita com double.
		rayCast->rayDirX = rayCast->dirX + rayCast->planeX * rayCast->cameraX;
		rayCast->rayDirY = rayCast->dirY + rayCast->planeY * rayCast->cameraX;

		// Wich box of the map
		rayCast->mapX = (int)rayCast->posX;
		rayCast->mapy = (int)rayCast->posY;

		// Length of ray from current position to next x or y-side
		if (rayCast->rayDirX == 0)
			rayCast->deltaDistX = 1e30;
		else
			rayCast->deltaDistX = fabs(1 / rayCast->dirX);

		if (rayCast->rayDirY == 0)
			rayCast->deltaDistY = 1e30;
		else
			rayCast->deltaDistY = fabs(1 / rayCast->rayDirY);

		// Clacultae step and initial sideDist
		if (rayCast->rayDirX < 0)
		{
			rayCast->stepX = -1;
			rayCast->sideDistX = (rayCast->posX - rayCast->mapX) * rayCast->deltaDistX;
		}
		else
		{
			rayCast->stepX = 1;
			rayCast->sideDistX = (rayCast->mapX + 1.0 - rayCast->posX) * rayCast->deltaDistX;
		}
		if (rayCast->rayDirY < 0)
		{
			rayCast->stepY = 1;
			rayCast->sideDistY = (rayCast->posY - rayCast->mapy) * rayCast->deltaDistY;
		}
		else
		{
			rayCast->stepY = 1;
			rayCast->sideDistY = (rayCast->mapy + 1.0 - rayCast->posY) * rayCast->deltaDistY;
		}

		// perform DDA
		rayCast->hit = 0;
		while (rayCast->hit == 0)
		{
			// Jump to next map square, eiher in x-direction, or in y-direction
			if (rayCast->sideDistX < rayCast->sideDistY)
			{
				rayCast->sideDistX += rayCast->deltaDistX;
				rayCast->mapX += rayCast->stepX;
				rayCast->side = 0;
			}
			else
			{
				rayCast->sideDistY += rayCast->deltaDistY;
				rayCast->mapy += rayCast->stepY;
				rayCast->side = 1;
			}
			// Check if ray has hit a wall
			if (worldMap[rayCast->mapX][rayCast->mapy] > 0)
				rayCast->hit = 1;
		}

		// Calculate distance projected on camera direction
		if (rayCast->side == 0)
			rayCast->perpWallDist = (rayCast->sideDistX - rayCast->deltaDistX);
		else
			rayCast->perpWallDist = (rayCast->sideDistY - rayCast->deltaDistY);

		// Calculate height of line to draw on screen

		rayCast->lineHeight = (int)(screenHeight / rayCast->perpWallDist);

		// Calculate lowest and highest pixel to fill in current stripe
		rayCast->drawStart = ((rayCast->lineHeight * -1) / 2) + (screenHeight / 2);
		if (rayCast->drawStart < 0)
			rayCast->drawStart = 0;
		rayCast->drawEnd = (rayCast->lineHeight / 2) + (screenHeight / 2);
		if (rayCast->drawEnd >= screenHeight)
			rayCast->drawEnd = screenHeight - 1;


		// Colorize walls
		if (worldMap[rayCast->mapX][rayCast->mapy] == 1)
			rayCast->color = 0xFF0000;
		if (worldMap[rayCast->mapX][rayCast->mapy] == 2)
			rayCast->color = 0x00FF11;
		if (worldMap[rayCast->mapX][rayCast->mapy] == 3)
			rayCast->color = 0x1100FF;
		if (worldMap[rayCast->mapX][rayCast->mapy] == 4)
			rayCast->color = 0xFFFFFF;
		else
			rayCast->color = 0xF7FF00;
		// give x and y side different brightness
		if (rayCast->side == 1)
			rayCast->color /= 2;
		for (int y = rayCast->drawStart; y < rayCast->drawEnd; y++)
			mlx_pixel_put(main->mlx, main->mlx_win, x, y, rayCast->color);
	}

	mlx_loop(main->mlx);
	free(rayCast);
	free(fps);
	free(main);
	return (0);
}
