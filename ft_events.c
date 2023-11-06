/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:30:54 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/06 14:42:47 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_main *main)
{
	mlx_destroy_window(main->mlx, main->mlx_win);
	mlx_destroy_display(main->mlx);
	free(main->mlx);
	free(main->fps);
	free(main->rayCast);
	free(main->move);
	free(main);
	exit(0);
	return (0);
}

void	ft_events(t_main *main)
{
	mlx_hook(main->mlx_win, 17, 0, close_window, main);
}
