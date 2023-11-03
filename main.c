/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:44 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/03 12:09:06 by brolivei         ###   ########.fr       */
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
	fps->time = 0; // Time current frame
	fps->oldTime = 0; // Time of previous frame
}

int	main()
{
	t_main		*main;

	main = malloc(sizeof(t_main));
	ft_initVar(main->rayCast, main->fps);
	main->mlx = mlx_init();
	main->mlx_win = mlx_new_window(main->mlx, screenWidth, screenHeight, "cub3d");
	/*
	for (int x = 0; x < screenWidth; x++)
	{
		// Calculate ray position and direction
		main->rayCast->cameraX = 2 * x / (double)screenWidth - 1; // x - coordinate in camera space
		// Dar cast em (double)screenWidth garante que a operacao e feita com double.
		main->rayCast->rayDirX = main->rayCast->dirX + main->rayCast->planeX * main->rayCast->cameraX;
		main->rayCast->rayDirY = main->rayCast->dirY + main->rayCast->planeY * main->rayCast->cameraX;

		// Wich box of the map
		main->rayCast->mapX = (int)main->rayCast->posX;
		main->rayCast->mapY = (int)main->rayCast->posY;

		// Length of ray from current position to next x or y-side
		if (main->rayCast->rayDirX == 0)
			main->rayCast->deltaDistX = 1e30;
		else
			main->rayCast->deltaDistX = fabs(1 / main->rayCast->dirX);

		if (main->rayCast->rayDirY == 0)
			main->rayCast->deltaDistY = 1e30;
		else
			main->rayCast->deltaDistY = fabs(1 / main->rayCast->rayDirY);

		// Clacultae step and initial sideDist
		if (main->rayCast->rayDirX < 0)
		{
			main->rayCast->stepX = -1;
			main->rayCast->sideDistX = (main->rayCast->posX - main->rayCast->mapX) * main->rayCast->deltaDistX;
		}
		else
		{
			main->rayCast->stepX = 1;
			main->rayCast->sideDistX = (main->rayCast->mapX + 1.0 - main->rayCast->posX) * main->rayCast->deltaDistX;
		}
		if (main->rayCast->rayDirY < 0)
		{
			main->rayCast->stepY = -1;
			main->rayCast->sideDistY = (main->rayCast->posY - main->rayCast->mapY) * main->rayCast->deltaDistY;
		}
		else
		{
			main->rayCast->stepY = 1;
			main->rayCast->sideDistY = (main->rayCast->mapY + 1.0 - main->rayCast->posY) * main->rayCast->deltaDistY;
		}

		// perform DDA
		main->rayCast->hit = 0;
		while (main->rayCast->hit == 0)
		{
			// Jump to next map square, eiher in x-direction, or in y-direction
			if (main->rayCast->sideDistX < main->rayCast->sideDistY)
			{
				main->rayCast->sideDistX += main->rayCast->deltaDistX;
				main->rayCast->mapX += main->rayCast->stepX;
				main->rayCast->side = 0;
			}
			else
			{
				main->rayCast->sideDistY += main->rayCast->deltaDistY;
				main->rayCast->mapY += main->rayCast->stepY;
				main->rayCast->side = 1;
			}
			// Check if ray has hit a wall
			if (worldMap[main->rayCast->mapX][main->rayCast->mapY] > 0)
				main->rayCast->hit = 1;
		}

		// Calculate distance projected on camera direction
		if (main->rayCast->side == 0)
			main->rayCast->perpWallDist = (main->rayCast->sideDistX - main->rayCast->deltaDistX);
		else
			main->rayCast->perpWallDist = (main->rayCast->sideDistY - main->rayCast->deltaDistY);

		// Calculate height of line to draw on screen

		main->rayCast->lineHeight = (int)(screenHeight / main->rayCast->perpWallDist);

		// Calculate lowest and highest pixel to fill in current stripe
		main->rayCast->drawStart = ((main->rayCast->lineHeight * -1) / 2) + (screenHeight / 2);
		if (main->rayCast->drawStart < 0)
			main->rayCast->drawStart = 0;
		main->rayCast->drawEnd = (main->rayCast->lineHeight / 2) + (screenHeight / 2);
		if (main->rayCast->drawEnd >= screenHeight)
			main->rayCast->drawEnd = screenHeight - 1;


		// Colorize walls
		if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 1)
			main->rayCast->color = 0xFF0000;
		if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 2)
			main->rayCast->color = 0x00FF11;
		if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 3)
			main->rayCast->color = 0x1100FF;
		if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 4)
			main->rayCast->color = 0xFFFFFF;
		else
			main->rayCast->color = 0xF7FF00;
		// give x and y side different brightness
		if (main->rayCast->side == 1)
			main->rayCast->color /= 2;
		for (int y = main->rayCast->drawStart; y < main->rayCast->drawEnd; y++)
			mlx_pixel_put(main->mlx, main->mlx_win, x, y, main->rayCast->color);
	}
	*/
	rayCasting(main, worldMap);
	mlx_loop(main->mlx);
	free(main->rayCast);
	free(main);
	return (0);
}
