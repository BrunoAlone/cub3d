/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:12:45 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/06 13:02:53 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_camera_and_dir(t_main *main, int x)
{
	main->rayCast->cameraX = 2 * x / (double)screenWidth - 1; // Coordenada x da camera no espaco
	main->rayCast->rayDirX = main->rayCast->dirX + main->rayCast->planeX * main->rayCast->cameraX;
	main->rayCast->rayDirY = main->rayCast->dirY + main->rayCast->planeY * main->rayCast->cameraX;
}

void	ft_cell_coordinate(t_main *main)
{
	/*
		Coordenadas da celula atual do mapa em que o raio se encontra.
		Obtidas convertendo a posicao atual do jogador para INT.

		A necessidade dessa conversao das atuais coordenadas do jogar
	que podem ser float, para numeros inteiros, e devido ao facto de estarmos
	a trabalhar com um mapa sendo uma grelha 2D. Cada celula do mapa tem coordenadas
	(0,0) (0,1) etc

		Entao para determinar em que celuala do mapa o raio esta, e necessario
	arredondar as coordenadas do jogador ao INT mais proximo.

		Exemplo:

			Se o jogador esta na posicao (2.3, 3.7) significa que ele
		esta na celula (2, 4). mapX = 2 e mapY = 4.
	*/
	main->rayCast->mapX = (int)main->rayCast->posX;
	main->rayCast->mapY = (int)main->rayCast->posY;
}

void	ft_lenght_to_next_edge(t_main *main)
{
	/*
			deltaDistX representa a distancia que o raio precisa percorrer para atingir
		a proxima aresta X. Se rayDirX for igual a 0 significa que o raio e paralelo
		ao eixo dos X, entao deltaDistX e definido com um valor grande para evitar divisao
		por zero.

			Caso contrario e calculador para o inverso da direcao X. E calculador com recurso
		a funcao de valor absoluto pois estamos a falar de distancias, entao nao faz sentido
		ter um numero negativo.
	*/
	if (main->rayCast->rayDirX == 0)
		main->rayCast->deltaDistX = 1e30;
	else
		main->rayCast->deltaDistX = fabs(1 / main->rayCast->rayDirX);
	if (main->rayCast->rayDirY == 0)
		main->rayCast->deltaDistY = 1e30;
	else
		main->rayCast->deltaDistY = fabs(1 / main->rayCast->rayDirY);
}

void	ft_step_initial_sideDist(t_main *main)
{
	/*
			StepX e StepY sao calculados com base na direcao do raio X e do raio Y.
			stepX ira indicar se o raio esta a ir na direcao esquerda do mapa (-1) ou direita (1).
			sideDistX representa a distancia do raio a primeira aresta a esquerda ou direita.
			stepY ira indicar se o raio esta a ir para cima (-1) ou para baixo (1).
			sideDistY representa a distancia do raio a primeira aresta acima ou abaixo.
	*/
	if (main->rayCast->rayDirX < 0)
	{
		main->rayCast->stepX = -1;
		main->rayCast->sideDistX = (main->rayCast->posX - main->rayCast->mapX) * main->rayCast->deltaDistX;
	}
	else
	{
		main->rayCast->stepX = 1;
		main->rayCast->sideDistX = (main->rayCast->mapX + 1.0 - main->rayCast->posX) * main->rayCast->deltaDistX;
	}
	if (main->rayCast->rayDirY < 0)
	{
		main->rayCast->stepY = -1;
		main->rayCast->sideDistY = (main->rayCast->posY - main->rayCast->mapY) * main->rayCast->deltaDistY;
	}
	else
	{
		main->rayCast->stepY = 1;
		main->rayCast->sideDistY = (main->rayCast->mapY + 1.0 - main->rayCast->posY) * main->rayCast->deltaDistY;
	}
}

void	ft_dda_perform(t_main *main, int worldMap[mapWidth][mapHeight])
{
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

void	ft_projection_distance(t_main *main)
{
	/*
				Calculo da distancia perpendicular da parade ao plano da camara e
			calculo da altura da linha que ira ser desenhada na tela.
	*/
	if (main->rayCast->side == 0)
		main->rayCast->perpWallDist = (main->rayCast->sideDistX - main->rayCast->deltaDistX);
	else
		main->rayCast->perpWallDist = (main->rayCast->sideDistY - main->rayCast->deltaDistY);
	main->rayCast->lineHeight = (int)(screenHeight / main->rayCast->perpWallDist);
}

void	ft_pixel_calculation(t_main *main)
{
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
	main->rayCast->drawStart = ((main->rayCast->lineHeight * -1) / 2) + (screenHeight / 2);
	if (main->rayCast->drawStart < 0)
		main->rayCast->drawStart = 0;
	main->rayCast->drawEnd = (main->rayCast->lineHeight / 2) + (screenHeight / 2);
	if (main->rayCast->drawEnd >= screenHeight)
		main->rayCast->drawEnd = screenHeight - 1;
}

void	ft_colorize(t_main *main, int worldMap[mapWidth][mapHeight])
{
	if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 1)
		main->rayCast->color = 0xFF0000;
	if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 2)
		main->rayCast->color = 0x00FF11;
	if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 3)
		main->rayCast->color = 0x1100FF;
	if (worldMap[main->rayCast->mapX][main->rayCast->mapY] == 4)
		main->rayCast->color = 0xFFFFFF;
	else
		main->rayCast->color = 0xF7FF00;
	if (main->rayCast->side == 1)
		main->rayCast->color /= 2;
}

void	rayCasting(t_main *main, int worldMap[mapWidth][mapHeight])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < screenWidth)
	{
		ft_camera_and_dir(main, x);
		ft_cell_coordinate(main);
		ft_lenght_to_next_edge(main);
		ft_step_initial_sideDist(main);
		ft_dda_perform(main, worldMap);
		ft_projection_distance(main);
		ft_pixel_calculation(main);
		ft_colorize(main, worldMap);
		y = main->rayCast->drawStart;
		while (y < main->rayCast->drawEnd)
		{
			mlx_pixel_put(main->mlx, main->mlx_win, x, y, main->rayCast->color);
			y++;
		}
		x++;
	}
}


/*
	int	worldMap[w][h]=
	{
		{11111},
		{10001},
		{10J01},
		{10001},
		{11111}
	};
*/
