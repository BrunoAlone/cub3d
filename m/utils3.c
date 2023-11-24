/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:39:41 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/11/24 12:18:32 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
