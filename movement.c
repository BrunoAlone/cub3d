/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/07 15:04:11 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_moveForward(t_main *main, int worldMap[mapWidth][mapHeight])
{
	if (worldMap[(int)(main->rayCast->posX + main->rayCast->dirX)]
		[(int)(main->rayCast->posY)] == 0)
	{
		printf("main->dirX = %f\n", main->rayCast->dirX);
		printf("main->posX = %f\n", main->rayCast->posX);
		printf("main->posY = %f\n\n", main->rayCast->posY);
		main->rayCast->posX += main->rayCast->dirX;
	}
	if (worldMap[(int)(main->rayCast->posX)]
		[(int)(main->rayCast->posY + main->rayCast->dirY)] == 0)
	{
		printf("main->dirY = %f\n", main->rayCast->dirY);
		printf("main->posX = %f\n", main->rayCast->posX);
		printf("main->posY = %f\n", main->rayCast->posY);
		main->rayCast->posY += main->rayCast->dirY;
	}
	mlx_clear_window(main->mlx, main->mlx_win);
	rayCasting(main, worldMap);
}

void	ft_moveBackwards(t_main *main)
{
	if (main->worldMap[(int)(main->rayCast->posX - main->rayCast->dirX)]
		[(int)(main->rayCast->posY)] == 0)
		main->rayCast->posX -= main->rayCast->dirX;
	if (main->worldMap[(int)(main->rayCast->posX)]
		[(int)(main->rayCast->posY - main->rayCast->dirY)] == 0)
		main->rayCast->posY -= main->rayCast->dirY;
	mlx_clear_window(main->mlx, main->mlx_win);
	rayCasting(main, main->worldMap);
}

void	ft_moveLeft(t_main *main)
{
	// Veirificar letras do player
	if (main->worldMap[(int)(main->rayCast->posX)]
		[(int)(main->rayCast->posY - 1)] == 0)
		main->rayCast->posY -= 1 * 0.2;
	mlx_clear_window(main->mlx, main->mlx_win);
	rayCasting(main, main->worldMap);
}

void	ft_moveRight(t_main *main)
{
	if (main->worldMap[(int)(main->rayCast->posX)]
		[(int)(main->rayCast->posY + 1)] == 0)
		main->rayCast->posY += 1;
	mlx_clear_window(main->mlx, main->mlx_win);
	rayCasting(main, main->worldMap);
}

/*
void	ft_moveLeft(t_main *main)
{
    double oldDirX = main->rayCast->dirX;
    main->rayCast->dirX = main->rayCast->dirX * cos(main->move->rotSpeed) - main->rayCast->dirY * sin(main->move->rotSpeed);
    main->rayCast->dirY = oldDirX * sin(main->move->rotSpeed) + main->rayCast->dirY * cos(main->move->rotSpeed);

    double oldPlaneX = main->rayCast->planeX;
    main->rayCast->planeX = main->rayCast->planeX * cos(main->move->rotSpeed) - main->rayCast->planeY * sin(main->move->rotSpeed);
    main->rayCast->planeY = oldPlaneX * sin(main->move->rotSpeed) + main->rayCast->planeY * cos(main->move->rotSpeed);

    mlx_clear_window(main->mlx, main->mlx_win);
    rayCasting(main, main->worldMap);
}
*/
