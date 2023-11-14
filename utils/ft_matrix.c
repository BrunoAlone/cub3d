/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:44:12 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/14 14:44:33 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_matrixCopy(int worldMap[mapWidth][mapHeight], t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mapWidth)
	{
		ft_memcpy(main->worldMap[i], worldMap[i], sizeof(worldMap[i]));
		i++;
	}
}
