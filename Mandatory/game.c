/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:44 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/21 11:17:07 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub.h"

int	moves(t_main *main)
{
	if (main->release == 0)
	{
		ft_move_forward(main);
		return (1);
	}
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
		new_image(main);
		ray_casting(main);
	}
	return (0);
}

int	game(t_cub *cub)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	ft_initvar(main, cub);
	initialize_mlx(main);
	ray_casting(main);
	ft_events(main);
	mlx_loop_hook(main->mlx, loop, main);
	mlx_loop(main->mlx);
	return (0);
}
