/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:18:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/21 12:22:02 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_forward(t_main *main)
{
	if (main->world_map[(int)(main->raycast->pos_x + main->raycast->dir_x * 0.02)]
		[(int)(main->raycast->pos_y)] != '1')
	{
		main->raycast->pos_x += main->raycast->dir_x * 0.01;
	}
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y + main->raycast->dir_y * 0.02)] != '1')
	{
		main->raycast->pos_y += main->raycast->dir_y * 0.01;
	}
}

void	ft_move_backwards(t_main *main)
{
	if (main->world_map[(int)(main->raycast->pos_x
			- main->raycast->dir_x * 0.02)]
		[(int)(main->raycast->pos_y)] != '1')
		main->raycast->pos_x -= main->raycast->dir_x * 0.01;
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y - main->raycast->dir_y * 0.02)] != '1')
		main->raycast->pos_y -= main->raycast->dir_y * 0.01;
}

void	ft_move_left(t_main *main)
{
	double	perpendicular_x;
	double	perpendicular_y;
	double	move_x;
	double	move_y;

	perpendicular_x = -main->raycast->dir_y;
	perpendicular_y = main->raycast->dir_x;
	move_x = perpendicular_x * 0.005;
	move_y = perpendicular_y * 0.005;
	if (main->world_map[(int)(main->raycast->pos_x + move_x)]
		[(int)(main->raycast->pos_y)] != '1')
		main->raycast->pos_x += move_x;
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y + move_y)] != '1')
		main->raycast->pos_y += move_y;
	// mlx_destroy_image(main->mlx, main->img->img);
	// new_image(main);
	// ray_casting(main);
}

void	ft_move_right(t_main *main)
{
	double	perpendicular_x;
	double	perpendicular_y;
	double	move_x;
	double	move_y;

	perpendicular_x = -main->raycast->dir_y;
	perpendicular_y = main->raycast->dir_x;
	move_x = perpendicular_x * 0.005 * (-1);
	move_y = perpendicular_y * 0.005 * (-1);
	if (main->world_map[(int)(main->raycast->pos_x + move_x)]
		[(int)(main->raycast->pos_y)] != '1')
		main->raycast->pos_x += move_x;
	if (main->world_map[(int)(main->raycast->pos_x)]
		[(int)(main->raycast->pos_y + move_y)] != '1')
		main->raycast->pos_y += move_y;
	// mlx_destroy_image(main->mlx, main->img->img);
	// new_image(main);
	// ray_casting(main);
}

void	ft_rotate_right(t_main *main)
{
	main->raycast->olddir_x = main->raycast->dir_x;
	main->raycast->dir_x = main->raycast->dir_x * cos(-0.02)
		- main->raycast->dir_y * sin(-0.02);
	main->raycast->dir_y = main->raycast->olddir_x * sin(-0.02)
		+ main->raycast->dir_y * cos(-0.02);
	main->raycast->oldplane_x = main->raycast->plane_x;
	main->raycast->plane_x = main->raycast->plane_x * cos(-0.02)
		- main->raycast->plane_y * sin(-0.02);
	main->raycast->plane_y = main->raycast->oldplane_x * sin(-0.02)
		+ main->raycast->plane_y * cos(-0.02);
	// mlx_destroy_image(main->mlx, main->img->img);
	// new_image(main);
	// ray_casting(main);
}

void	ft_rotate_left(t_main *main)
{
	main->raycast->olddir_x = main->raycast->dir_x;
	main->raycast->dir_x = main->raycast->dir_x * cos(0.02)
		- main->raycast->dir_y * sin(0.02);
	main->raycast->dir_y = main->raycast->olddir_x * sin(0.02)
		+ main->raycast->dir_y * cos(0.02);
	main->raycast->oldplane_x = main->raycast->plane_x;
	main->raycast->plane_x = main->raycast->plane_x * cos(0.02)
		- main->raycast->plane_y * sin(0.02);
	main->raycast->plane_y = main->raycast->oldplane_x * sin(0.02)
		+ main->raycast->plane_y * cos(0.02);
	// mlx_destroy_image(main->mlx, main->img->img);
	// new_image(main);
	// ray_casting(main);
}
