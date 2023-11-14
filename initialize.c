/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:35:02 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/14 14:43:47 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_direction(t_main *main, char dir)
{
	if (dir == 'N')
	{
		main->rayCast->dirX = 0;
		main->rayCast->dirY = -1;
		main->rayCast->planeX = -0.66;
		main->rayCast->planeY = 0;
	}
	if (dir == 'S')
	{
		main->rayCast->dirX = 0;
		main->rayCast->dirY = 1;
		main->rayCast->planeX = 0.66;
		main->rayCast->planeY = 0;
	}
	if (dir == 'E')
	{
		main->rayCast->dirX = 1;
		main->rayCast->dirY = 0;
		main->rayCast->planeX = 0;
		main->rayCast->planeY = -0.66;
	}
	if (dir == 'W')
	{
		main->rayCast->dirX = -1;
		main->rayCast->dirY = 0;
		main->rayCast->planeX = 0;
		main->rayCast->planeY = 0.66;
	}
}

void	ft_tex(t_main *main)
{
	main->paths[0] = ft_strdup("tex/n.xpm");
	main->paths[1] = ft_strdup("tex/s.xpm");
	main->paths[2] = ft_strdup("tex/e.xpm");
	main->paths[3] = ft_strdup("tex/w.xpm");
}

void	ft_allocate_mem(t_main *main)
{
	main->rayCast = malloc(sizeof(t_rayCast));
	main->img = malloc(sizeof(t_image));
	main->n_tex = malloc(sizeof(t_image));
	main->s_tex = malloc(sizeof(t_image));
	main->e_tex = malloc(sizeof(t_image));
	main->w_tex = malloc(sizeof(t_image));
	main->paths = malloc(4 * sizeof(char *));
	main->f_c = malloc(sizeof(t_f_c));
	ft_tex(main);
}

void	ft_initVar(t_main *main, int worldMap[mapWidth][mapHeight])
{
	ft_allocate_mem(main);
	ft_matrixCopy(worldMap, main);
	main->rayCast->posX = 22; // x start position
	main->rayCast->posY = 12;		  // y start position
	ft_find_direction(main, 'S');
	main->f_c->floor = 0x228B22;
	main->f_c->ceiling = 0x87CEEB;
}
