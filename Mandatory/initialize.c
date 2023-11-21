/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:35:02 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/20 13:49:28 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub.h"

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

void	ft_tex(t_main *main, t_cub *cub)
{
	main->paths[0] = ft_strdup(cub->ntext);
	main->paths[1] = ft_strdup(cub->stext);
	main->paths[2] = ft_strdup(cub->etext);
	main->paths[3] = ft_strdup(cub->wtext);
}

void	ft_allocate_matrix(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	main->world_map = (char**)malloc(main->map_width * sizeof(char *));
	if (main->world_map == NULL)
		return ;
	while (i < main->map_width)
	{
		main->world_map[i] = (char*)malloc(main->map_height * sizeof(char));
		i++;
	}
}

void	ft_allocate_mem(t_main *main, t_cub *cub)
{
	main->raycast = malloc(sizeof(t_rayCast));
	main->img = malloc(sizeof(t_image));
	main->n_tex = malloc(sizeof(t_image));
	main->s_tex = malloc(sizeof(t_image));
	main->e_tex = malloc(sizeof(t_image));
	main->w_tex = malloc(sizeof(t_image));
	main->paths = malloc(4 * sizeof(char *));
	main->f_c = malloc(sizeof(t_f_c));
	main->map_width = cub->t_height;
	main->map_height = cub->length;
	ft_allocate_matrix(main);
	ft_tex(main, cub);
}

void	ft_initvar(t_main *main, t_cub *cub)
{
	ft_allocate_mem(main, cub);
	ft_matrix_copy(cub->t_map, main, cub);
	main->raycast->pos_x = cub->py;
	main->raycast->pos_y = cub->px;
	ft_find_direction(main, cub->player);
	main->f_c->floor = cub->fcolor;
	main->f_c->ceiling = cub->ccolor;
}
