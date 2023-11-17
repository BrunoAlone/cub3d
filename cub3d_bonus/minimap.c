/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:12:46 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/17 11:30:17 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_main *main, t_image *m_image)
{
	int	x;
	int	y;
	int mat_x;
	int mat_y;

	x = 0;
	y = 0;
	while (x < (SCREEN_WIDTH / 5))
	{
		y = 0;
		while (y < (SCREEN_HEIGHT / 5))
		{
			mat_x = x * 24 / (SCREEN_WIDTH / 5);
			mat_y = y * 24 / (SCREEN_HEIGHT / 5);
			if (main->world_map[mat_x][mat_y] == 0)
				my_mlx_pixel_put(m_image, x, y, 0xFFFFFF);
			if (main->world_map[mat_x][mat_y] == 1)
				my_mlx_pixel_put(m_image, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	render_player(t_main *main, t_image *m_map)
{
	int	x;
	int	y;
	double mat_x;
	double mat_y;

	x = 0;
	y = 0;
	while (x < (SCREEN_WIDTH / 5))
	{
		y = 0;
		while (y < (SCREEN_HEIGHT / 5))
		{
			mat_x = (int)(x * 24 / (SCREEN_WIDTH / 5));
			mat_y = (int)(y * 24 / (SCREEN_HEIGHT / 5));
			if (mat_x == (int)main->raycast->pos_x && mat_y == (int)main->raycast->pos_y)
				my_mlx_pixel_put(m_map, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_main *main)
{
	t_image	*mini_map;
	int	x;
	int	y;

	x = 0;
	y = 0;
	mini_map = malloc(sizeof(t_image));
	mini_map->img = mlx_new_image(main->mlx, (SCREEN_WIDTH / 5),
		(SCREEN_HEIGHT / 5));
	mini_map->addr = mlx_get_data_addr(mini_map->img, &mini_map->bpp,
		&mini_map->line_length, &mini_map->endian);
	render_minimap(main, mini_map);
	render_player(main, mini_map);
	mlx_put_image_to_window(main->mlx, main->mlx_win, mini_map->img,
		10, 10);
}

