/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:27:43 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/07 14:05:25 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		n--;
		i++;
	}
	return (dst);
}
/*
int	main()
{
	unsigned char	src[] = "Hola Amigo!";
	unsigned char	dest[5];
	unsigned char	src1[] = "Hola Amigo!";
	unsigned char	dest1[5];

	ft_memcpy(dest, src, 4);
	memcpy(dest1, src1, 4);
	printf("%s\n", dest);
	printf("%s\n", dest1);
	return(0);
}*/
