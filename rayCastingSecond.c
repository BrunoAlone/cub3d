/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastingSecond.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:30 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/14 15:12:54 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
			Realizando o algoritmo DDA(Digital Differential Analyzer) para
		determinar qual parade foi atingida pelo raio.

			main->rayCast->hit = 0; - Inicializa a variavel hit a zero, indicando que
		o raio nao atingiu a parede.

			Entramos num loop que continuara enquanto nenhum raio atingir uma parede.

			Dentro do loop verificamos qual raio atingira uma aresta primeiro, se aresta
		de X ou de Y.
			Isso e feito comparando as distancias ja calculadas de sideDistX(distancia
		ate a proxima aresta no eixo X) com sideDistY(distancia ate a proxima aresta no
		eixo Y). Se sideDistX for menor, o raio avanca no eixo X, caso contrario, no Y.

			A posicao do mapa (mapX e mapY) e atualizada de acordo com a direcao do raio(stepX e stepY).

			side e atualizado para percebermos qual lado foi atingido, se X ou se Y.

			Por fim, e verificado se a posicao atual no mapa e uma parede e se sim,
		o loop e encerrado.
*/

void	ft_dda_perform(t_main *main, int worldMap[mapWidth][mapHeight])
{
	main->rayCast->hit = 0;
	while (main->rayCast->hit == 0)
	{
		if (main->rayCast->sideDistX < main->rayCast->sideDistY)
		{
			main->rayCast->sideDistX += main->rayCast->deltaDistX;
			main->rayCast->mapX += main->rayCast->stepX;
			main->rayCast->side = 0;
		}
		else
		{
			main->rayCast->sideDistY += main->rayCast->deltaDistY;
			main->rayCast->mapY += main->rayCast->stepY;
			main->rayCast->side = 1;
		}
		if (worldMap[main->rayCast->mapX][main->rayCast->mapY] > 0)
			main->rayCast->hit = 1;
	}
}

/*
			Calculo da distancia perpendicular da parade ao plano da camara e
		calculo da altura da linha que ira ser desenhada na tela.
*/

void	ft_projection_distance(t_main *main)
{
	if (main->rayCast->side == 0)
		main->rayCast->perpWallDist = (main->rayCast->sideDistX - main->rayCast->deltaDistX);
	else
		main->rayCast->perpWallDist = (main->rayCast->sideDistY - main->rayCast->deltaDistY);


	if (main->rayCast->perpWallDist != 0)
		main->rayCast->lineHeight = (int)(screenHeight / main->rayCast->perpWallDist);
	else
		main->rayCast->lineHeight = (int)screenHeight;
}

/*
		Determinacao dos pixeis mais altos e mais baixo que serao preenchidos
	na faixa vertical.

		drawStart e calculado subtraindo metade da lineHeight do meio da tela (screenHeight / 2).
	Isso servira para posicionar a linha de inicio da parede corretamente na tela.
		E verificado se o resultado e menor que zero. Se for, e ajustado para zera para
	garantir que nao haja valores negativos.

		drawEnd e calculado somando metade da lineHeight ao meio da tela (sreenHeight / 2).
	Isso determina a linha de fim da parede.
		E verificado se o calculo ultrapassa a linha maxima de altura. Se sim, e ajustada
	para o valor maximo da altura.
*/

void	ft_pixel_calculation(t_main *main)
{
	main->rayCast->drawStart = -main->rayCast->lineHeight / 2 + screenHeight / 2;
	if (main->rayCast->drawStart < 0)
		main->rayCast->drawStart = 0;
	main->rayCast->drawEnd = (main->rayCast->lineHeight / 2) + screenHeight / 2;
	if (main->rayCast->drawEnd >= screenHeight)
		main->rayCast->drawEnd = screenHeight - 1;
}

void	ft_side_of_pixel(t_main *main)
{
	if (main->rayCast->side == 1)
	{
		if (main->rayCast->rayDirY < 0)
			main->tex = main->n_tex;
		else
			main->tex = main->s_tex;
	}
	else
	{
		if (main->rayCast->rayDirX < 0)
			main->tex = main->w_tex;
		else
			main->tex = main->e_tex;
	}
}

void	raySecondsSteps(t_main *main)
{
	ft_dda_perform(main, main->worldMap);
	ft_projection_distance(main);
	ft_pixel_calculation(main);
	ft_side_of_pixel(main);
}
