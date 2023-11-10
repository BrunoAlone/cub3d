/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:41 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/10 14:14:16 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_xpm_image(t_main *main)
{
	main->rayCast->tex->img = mlx_xpm_file_to_image(main->mlx, "tex.xpm",
								&main->rayCast->tex->w, &main->rayCast->tex->h);
	main->rayCast->tex->addr = mlx_get_data_addr(main->rayCast->tex->img, &main->rayCast->tex->bpp,
								&main->rayCast->tex->line_length, &main->rayCast->tex->endian);
}

void	initialize_mlx(t_main *main)
{
	main->mlx = mlx_init();
	main->mlx_win = mlx_new_window(main->mlx, screenWidth, screenHeight, "cub3d");
	main->img->img = mlx_new_image(main->mlx, screenWidth, screenHeight);
	main->img->addr = mlx_get_data_addr(main->img->img,
		&main->img->bpp, &main->img->line_length,
		&main->img->endian);
	get_xpm_image(main);
}

void	new_image(t_main *main)
{
	main->img->img = mlx_new_image(main->mlx, screenWidth, screenHeight);
	main->img->addr = mlx_get_data_addr(main->img->img,
		&main->img->bpp, &main->img->line_length,
		&main->img->endian);
}
