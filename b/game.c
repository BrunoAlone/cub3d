/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:44 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/26 20:15:31 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub.h"

int	moves(t_main *main)
{
	int	x;

	x = main->wr + main->sr + main->ar + main->dr
		+ main->rightr + main->leftr + main->er + main->mr;
	if (main->wr == 1)
		ft_move_forward(main);
	if (main->sr == 1)
		ft_move_backwards(main);
	if (main->ar == 1)
		ft_move_left(main);
	if (main->dr == 1)
		ft_move_right(main);
	if (main->rightr == 1)
		ft_rotate_right(main);
	if (main->leftr == 1)
		ft_rotate_left(main);
	if (x > 0)
		return (1);
	return (0);
}

int	loop(t_main *main)
{
	int	control;

	control = moves(main);
	if (control == 0)
		return (0);
	else
	{
		mlx_destroy_image(main->mlx, main->img->img);
		mlx_destroy_image(main->mlx, main->minimap->img);
		new_image(main);
		ray_casting(main, 0, 0);
	}
	return (0);
}

int	game(t_cub *cub)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	ft_initvar(main, cub);
	initialize_mlx(main);
	ray_casting(main, 0, 0);
	ft_events(main);
	mlx_loop_hook(main->mlx, loop, main);
	mlx_loop(main->mlx);
	return (0);
}
