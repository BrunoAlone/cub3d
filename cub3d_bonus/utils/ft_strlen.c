/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:57:29 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/13 12:11:52 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include<stdio.h>

int	main()
{
	char	str[] = "Hola!";

	printf("R: %ld\n", ft_strlen(str));
	printf("R: %ld\n", strlen(str));
	return(0);
}*/
