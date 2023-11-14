/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastingFirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/14 15:04:57 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_camera_and_dir(t_main *main, int x)
{
	main->rayCast->cameraX = 2 * x / (double)screenWidth - 1; // Coordenada x da camera no espaco
	main->rayCast->rayDirX = main->rayCast->dirX + main->rayCast->planeX * main->rayCast->cameraX;
	main->rayCast->rayDirY = main->rayCast->dirY + main->rayCast->planeY * main->rayCast->cameraX;
}

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

void	ft_cell_coordinate(t_main *main)
{
	main->rayCast->mapX = (int)main->rayCast->posX;
	main->rayCast->mapY = (int)main->rayCast->posY;
}

/*
		deltaDistX representa a distancia que o raio precisa percorrer para atingir
	a proxima aresta X. Se rayDirX for igual a 0 significa que o raio e paralelo
	ao eixo dos X, entao deltaDistX e definido com um valor grande para evitar divisao
	por zero.

		Caso contrario e calculador para o inverso da direcao X. E calculador com recurso
	a funcao de valor absoluto pois estamos a falar de distancias, entao nao faz sentido
	ter um numero negativo.
*/

void	ft_lenght_to_next_edge(t_main *main)
{
	if (main->rayCast->rayDirX == 0)
		main->rayCast->deltaDistX = 1e30;
	else
		main->rayCast->deltaDistX = fabs(1 / main->rayCast->rayDirX);
	if (main->rayCast->rayDirY == 0)
		main->rayCast->deltaDistY = 1e30;
	else
		main->rayCast->deltaDistY = fabs(1 / main->rayCast->rayDirY);
}

/*
		StepX e StepY sao calculados com base na direcao do raio X e do raio Y.
		stepX ira indicar se o raio esta a ir na direcao esquerda do mapa (-1) ou direita (1).
		sideDistX representa a distancia do raio a primeira aresta a esquerda ou direita.
		stepY ira indicar se o raio esta a ir para cima (-1) ou para baixo (1).
		sideDistY representa a distancia do raio a primeira aresta acima ou abaixo.
*/

void	ft_step_initial_sideDist(t_main *main)
{
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

void	rayFirstSteps(t_main *main, int x)
{
	ft_camera_and_dir(main, x);
	ft_cell_coordinate(main);
	ft_lenght_to_next_edge(main);
	ft_step_initial_sideDist(main);
}
