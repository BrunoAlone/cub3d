/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:30:54 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/16 12:23:03 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_main *main)
{
	mlx_destroy_image(main->mlx, main->img->img);
	mlx_destroy_image(main->mlx, main->n_tex->img);
	mlx_destroy_image(main->mlx, main->s_tex->img);
	mlx_destroy_image(main->mlx, main->e_tex->img);
	mlx_destroy_image(main->mlx, main->w_tex->img);
	mlx_destroy_window(main->mlx, main->mlx_win);
	mlx_destroy_display(main->mlx);
	free(main->n_tex);
	free(main->s_tex);
	free(main->e_tex);
	free(main->w_tex);
	free(main->paths[0]);
	free(main->paths[1]);
	free(main->paths[2]);
	free(main->paths[3]);
	free(main->paths);
	free(main->img);
	free(main->mlx);
	free(main->raycast);
	free(main->f_c);
	free(main);
	exit(0);
	return (0);
}

int	movement(int keycode, t_main *main)
{
	if (keycode == W)
		ft_move_forward(main, main->world_map);
	if (keycode == S)
		ft_move_backwards(main);
	if (keycode == A)
		ft_move_left(main);
	if (keycode == D)
		ft_move_right(main);
	if (keycode == RIGHT)
		ft_rotate_right(main);
	if (keycode == LEFT)
		ft_rotate_left(main);
	if (keycode == ESC)
		close_window(main);
	return (0);
}

void	ft_events(t_main *main)
{
	mlx_key_hook(main->mlx_win, movement, main);
	mlx_hook(main->mlx_win, 17, 0, close_window, main);
}
