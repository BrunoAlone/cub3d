/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/08 14:13:11 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_moveForward(t_main *main, int worldMap[mapWidth][mapHeight])
{
	if (worldMap[(int)(main->rayCast->posX + main->rayCast->dirX * 0.2)]
		[(int)(main->rayCast->posY)] == 0)
	{
		main->rayCast->posX += main->rayCast->dirX * 0.2;
	}
	if (worldMap[(int)(main->rayCast->posX)]
		[(int)(main->rayCast->posY + main->rayCast->dirY * 0.2)] == 0)
	{
		main->rayCast->posY += main->rayCast->dirY * 0.2;
	}
	mlx_clear_window(main->mlx, main->mlx_win);
	rayCasting(main, worldMap);
}

void	ft_moveBackwards(t_main *main)
{
	if (main->worldMap[(int)(main->rayCast->posX - main->rayCast->dirX * 0.2)]
		[(int)(main->rayCast->posY)] == 0)
		main->rayCast->posX -= main->rayCast->dirX * 0.2;
	if (main->worldMap[(int)(main->rayCast->posX)]
		[(int)(main->rayCast->posY - main->rayCast->dirY * 0.2)] == 0)
		main->rayCast->posY -= main->rayCast->dirY * 0.2;
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
		main->rayCast->posY += 1 * 0.2;
	mlx_clear_window(main->mlx, main->mlx_win);
	rayCasting(main, main->worldMap);
}

void	ft_rotate_right(t_main *main)
{
	main->rayCast->oldDirX = main->rayCast->dirX;
	main->rayCast->dirX = main->rayCast->dirX * cos(-0.2) - main->rayCast->dirY * sin(-0.2);
	main->rayCast->dirY = main->rayCast->oldDirX * sin(-0.2) + main->rayCast->dirY * cos(-0.2);
	main->rayCast->oldPlaneX = main->rayCast->planeX;
	main->rayCast->planeX = main->rayCast->planeX * cos(-0.2) - main->rayCast->planeY * sin(-0.2);
	main->rayCast->planeY = main->rayCast->oldPlaneX * sin(-0.2) + main->rayCast->planeY * cos(-0.2);
	mlx_clear_window(main->mlx, main->mlx_win);
	rayCasting(main, main->worldMap);
}

void	ft_rotate_left(t_main *main)
{
	main->rayCast->oldDirX = main->rayCast->dirX;
	main->rayCast->dirX = main->rayCast->dirX * cos(0.2) - main->rayCast->dirY * sin(0.2);
	main->rayCast->dirY = main->rayCast->oldDirX * sin(0.2) + main->rayCast->dirY * cos(0.2);
	main->rayCast->oldPlaneX = main->rayCast->planeX;
	main->rayCast->planeX = main->rayCast->planeX * cos(0.2) - main->rayCast->planeY * sin(0.2);
	main->rayCast->planeY = main->rayCast->oldPlaneX * sin(0.2) + main->rayCast->planeY * cos(0.2);
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
