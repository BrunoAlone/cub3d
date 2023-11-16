/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:35:02 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/16 12:24:16 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_direction(t_main *main, char dir)
{
	if (dir == 'N')
	{
		main->raycast->dir_x = 0;
		main->raycast->dir_y = -1;
		main->raycast->plane_x = -0.66;
		main->raycast->plane_y = 0;
	}
	if (dir == 'S')
	{
		main->raycast->dir_x = 0;
		main->raycast->dir_y = 1;
		main->raycast->plane_x = 0.66;
		main->raycast->plane_y = 0;
	}
	if (dir == 'E')
	{
		main->raycast->dir_x = 1;
		main->raycast->dir_y = 0;
		main->raycast->plane_x = 0;
		main->raycast->plane_y = -0.66;
	}
	if (dir == 'W')
	{
		main->raycast->dir_x = -1;
		main->raycast->dir_y = 0;
		main->raycast->plane_x = 0;
		main->raycast->plane_y = 0.66;
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
	main->raycast = malloc(sizeof(t_rayCast));
	main->img = malloc(sizeof(t_image));
	main->n_tex = malloc(sizeof(t_image));
	main->s_tex = malloc(sizeof(t_image));
	main->e_tex = malloc(sizeof(t_image));
	main->w_tex = malloc(sizeof(t_image));
	main->paths = malloc(4 * sizeof(char *));
	main->f_c = malloc(sizeof(t_f_c));
	ft_tex(main);
}

void	ft_initvar(t_main *main, int worldMap[MAP_WIDTH][MAP_HEIGHT])
{
	ft_allocate_mem(main);
	ft_matrix_copy(worldMap, main);
	main->raycast->pos_x = 22;
	main->raycast->pos_y = 12;
	ft_find_direction(main, 'S');
	main->f_c->floor = 0x228B22;
	main->f_c->ceiling = 0x87CEEB;
}
