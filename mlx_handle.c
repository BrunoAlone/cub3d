/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:41 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/09 14:47:12 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_mlx(t_main *main)
{
	main->mlx = mlx_init();
	main->mlx_win = mlx_new_window(main->mlx, screenWidth, screenHeight, "cub3d");
	main->img->img = mlx_new_image(main->mlx, screenWidth, screenHeight);
	main->img->addr = mlx_get_data_addr(main->img->img,
		&main->img->bits_per_pixel, &main->img->line_length,
		&main->img->endian);
	main->tex->tex->img = mlx_xpm_file_to_image(main->mlx, "tex.xpm", &main->tex->width, &main->tex->height);
	main->tex->tex->addr = mlx_get_data_addr(main->tex->tex->img, &main->tex->tex->bits_per_pixel,
							&main->tex->tex->line_length, &main->tex->tex->endian);
}

void	new_image(t_main *main)
{
	main->img->img = mlx_new_image(main->mlx, screenWidth, screenHeight);
	main->img->addr = mlx_get_data_addr(main->img->img,
		&main->img->bits_per_pixel, &main->img->line_length,
		&main->img->endian);
}
