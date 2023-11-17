/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:44:12 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/16 11:14:09 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_matrix_copy(int world_map[MAP_WIDTH][MAP_HEIGHT], t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MAP_WIDTH)
	{
		ft_memcpy(main->world_map[i], world_map[i], sizeof(world_map[i]));
		i++;
	}
}
