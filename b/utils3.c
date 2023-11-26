/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:39:41 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/26 19:58:37 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color(t_check *check, char *s, int i, int j)
{
	if (!ft_strncmp(s, "C", 1) || !ft_strncmp(s, "F", 1))
	{
		while (s[i] == 32 || s[i] == 9)
			i++;
		if (s[i] == '\n')
			return (printf("error no color\n"), 1);
		while ((s[i] != 32 && s[i] != 9 && s[i] != '\n'))
		{
			j = i;
			while ((s[i] != ',' && check->comma != 2 && s[i]) || (s[i] != 32
					&& s[i] != '\n' && s[i] != 9 && check->comma == 2))
				i++;
			if (redcol(&s[j], (i - j)))
				return (1);
			if (s[i] == ',')
				check->comma += 1;
			if (s[i] == ',')
				i += 1;
		}
		while (s[i] == 32 || s[i] == 9)
			i++;
		if (s[i] != '\n' || s[i - 1] == ',')
			return (printf("many textures\n"), 1);
	}
	return (check->comma = 0, 0);
}

void	ft_free(void *content)
{
	if (!content)
		return ;
	free(content);
}

void	destroy_img(t_main *main)
{
	if (main->img->img)
		mlx_destroy_image(main->mlx, main->img->img);
	if (main->n_tex->img)
		mlx_destroy_image(main->mlx, main->n_tex->img);
	if (main->s_tex->img)
		mlx_destroy_image(main->mlx, main->s_tex->img);
	if (main->e_tex->img)
		mlx_destroy_image(main->mlx, main->e_tex->img);
	if (main->w_tex->img)
		mlx_destroy_image(main->mlx, main->w_tex->img);
	if (main->d_tex->img)
		mlx_destroy_image(main->mlx, main->d_tex->img);
	if (main->minimap->img)
		mlx_destroy_image(main->mlx, main->minimap->img);
	else
		return ;
}

int	ft_door(t_main *main)
{
	if (main->world_map[(int)(main->raycast->pos_x
			+ main->raycast->dir_x * 1)]
		[(int)(main->raycast->pos_y)] == '2')
		main->world_map[(int)(main->raycast->pos_x
				+ main->raycast->dir_x * 1)]
		[(int)(main->raycast->pos_y)] = '3';
	else if (main->world_map[(int)(main->raycast->pos_x
			+ main->raycast->dir_x * 1)]
			[(int)(main->raycast->pos_y)] == '3')
		main->world_map[(int)(main->raycast->pos_x
				+ main->raycast->dir_x * 1)]
		[(int)(main->raycast->pos_y)] = '2';
	return (0);
}
