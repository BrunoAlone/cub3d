/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:12:46 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/26 20:19:37 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_main *main, t_image *m_image, int x, int y)
{
	int	mat_x;
	int	mat_y;

	while (x < (SCREEN_WIDTH / 5))
	{
		y = 0;
		while (y < (SCREEN_HEIGHT / 3))
		{
			mat_x = (int)(x * main->map_width / (SCREEN_WIDTH / 5));
			mat_y = (int)(y * main->map_height / (SCREEN_HEIGHT / 3));
			if (main->world_map[mat_x][mat_y] == '2')
				my_mlx_pixel_put(m_image, x, y, 0xFF0000);
			else if (main->world_map[mat_x][mat_y] == '3')
				my_mlx_pixel_put(m_image, x, y, 0x00FF00);
			else if (main->world_map[mat_x][mat_y] == '1')
				my_mlx_pixel_put(m_image, x, y, 0x0000FF);
			else if (main->world_map[mat_x][mat_y] == 'X')
				my_mlx_pixel_put(m_image, x, y, 0x000000);
			else
				my_mlx_pixel_put(m_image, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

void	render_player(t_main *main, t_image *m_map)
{
	int			x;
	int			y;
	double		mat_x;
	double		mat_y;

	x = 0;
	y = 0;
	while (x < (SCREEN_WIDTH / 5))
	{
		y = 0;
		while (y < (SCREEN_HEIGHT / 3))
		{
			mat_x = (int)(x * main->map_width / (SCREEN_WIDTH / 5));
			mat_y = (int)(y * main->map_height / (SCREEN_HEIGHT / 3));
			if (mat_x == (int)main->raycast->pos_x
				&& mat_y == (int)main->raycast->pos_y)
				my_mlx_pixel_put(m_map, x, y, 0xFF4500);
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_main *main)
{
	main->minimap->img = mlx_new_image(main->mlx, (SCREEN_WIDTH / 5),
			(SCREEN_HEIGHT / 3));
	main->minimap->addr = mlx_get_data_addr(main->minimap->img,
			&main->minimap->bpp,
			&main->minimap->line_length, &main->minimap->endian);
	render_minimap(main, main->minimap, 0, 0);
	render_player(main, main->minimap);
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->minimap->img,
		5, 5);
}
