/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:41 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/07 09:46:26 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_mlx(t_main *main)
{
	main->mlx = mlx_init();
	main->mlx_win = mlx_new_window(main->mlx, screenWidth, screenHeight, "cub3d");
}
