/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:44 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/06 14:39:51 by brolivei         ###   ########.fr       */
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

/*
int worldMap[mapWidth][mapHeight] =
{
 {1,1,1,1,1},
 {1,0,0,0,1},
 {1,0,0,0,1},
 {1,0,0,0,1},
 {1,1,1,1,1}
};
*/

void	ft_initVar(t_rayCast *rayCast, t_FPS *fps)
{
	rayCast->posX = 22; // x start position
	rayCast->posY = 12; // y start position
	rayCast->dirX = -1; // Initial direction position x
	rayCast->dirY = 0; // Intitial direction position y
	rayCast->planeX = 0;
	rayCast->planeY = 0.66;
	fps->frameStart = clock();
}

void	fps_calculation(t_main *main)
{
	main->fps->frameEnd = clock();
	main->fps->frameTime = ((double)(main->fps->frameEnd - main->fps->frameStart)) / CLOCKS_PER_SEC;
	main->fps->fps = 1.0 / main->fps->frameTime;
	sprintf(main->fps->fpsString, "FPS: %.2f", main->fps->fps);
	mlx_string_put(main->mlx, main->mlx_win, 10, 10, 0xFFFFFF, main->fps->fpsString);
}

int	main()
{
	t_main		*main;

	main = malloc(sizeof(t_main));
	main->rayCast = malloc(sizeof(t_rayCast));
	main->fps = malloc(sizeof(t_FPS));
	main->move = malloc(sizeof(t_move));
	ft_initVar(main->rayCast, main->fps);
	main->mlx = mlx_init();
	main->mlx_win = mlx_new_window(main->mlx, screenWidth, screenHeight, "cub3d");
	rayCasting(main, worldMap);
	fps_calculation(main);
	// speed modifiers
	main->move->moveSpeed = main->fps->frameTime * 5.0;
	main->move->rotSpeed = main->fps->frameTime * 3.0;
	ft_events(main);
	mlx_loop(main->mlx);
	free(main->rayCast);
	free(main);
	return (0);
}
