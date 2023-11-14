/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:12:45 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/14 15:16:45 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_dda_perform(t_main *main, int worldMap[mapWidth][mapHeight])
// {
// 	/*
// 				Realizando o algoritmo DDA(Digital Differential Analyzer) para
// 			determinar qual parade foi atingida pelo raio.

// 				main->rayCast->hit = 0; - Inicializa a variavel hit a zero, indicando que
// 			o raio nao atingiu a parede.

// 				Entramos num loop que continuara enquanto nenhum raio atingir uma parede.

// 				Dentro do loop verificamos qual raio atingira uma aresta primeiro, se aresta
// 			de X ou de Y.
// 				Isso e feito comparando as distancias ja calculadas de sideDistX(distancia
// 			ate a proxima aresta no eixo X) com sideDistY(distancia ate a proxima aresta no
// 			eixo Y). Se sideDistX for menor, o raio avanca no eixo X, caso contrario, no Y.

// 				A posicao do mapa (mapX e mapY) e atualizada de acordo com a direcao do raio(stepX e stepY).

// 				side e atualizado para percebermos qual lado foi atingido, se X ou se Y.

// 				Por fim, e verificado se a posicao atual no mapa e uma parede e se sim,
// 			o loop e encerrado.
// 	*/
// 	main->rayCast->hit = 0;
// 	while (main->rayCast->hit == 0)
// 	{
// 		if (main->rayCast->sideDistX < main->rayCast->sideDistY)
// 		{
// 			main->rayCast->sideDistX += main->rayCast->deltaDistX;
// 			main->rayCast->mapX += main->rayCast->stepX;
// 			main->rayCast->side = 0;
// 		}
// 		else
// 		{
// 			main->rayCast->sideDistY += main->rayCast->deltaDistY;
// 			main->rayCast->mapY += main->rayCast->stepY;
// 			main->rayCast->side = 1;
// 		}
// 		if (worldMap[main->rayCast->mapX][main->rayCast->mapY] > 0)
// 			main->rayCast->hit = 1;
// 	}
// }

// void	ft_projection_distance(t_main *main)
// {
// 	/*
// 				Calculo da distancia perpendicular da parade ao plano da camara e
// 			calculo da altura da linha que ira ser desenhada na tela.
// 	*/
// 	if (main->rayCast->side == 0)
// 		main->rayCast->perpWallDist = (main->rayCast->sideDistX - main->rayCast->deltaDistX);
// 	else
// 		main->rayCast->perpWallDist = (main->rayCast->sideDistY - main->rayCast->deltaDistY);


// 	if (main->rayCast->perpWallDist != 0)
// 		main->rayCast->lineHeight = (int)(screenHeight / main->rayCast->perpWallDist);
// 	else
// 		main->rayCast->lineHeight = (int)screenHeight;
// }

// void	ft_pixel_calculation(t_main *main)
// {
// 	/*
// 			Determinacao dos pixeis mais altos e mais baixo que serao preenchidos
// 		na faixa vertical.

// 			drawStart e calculado subtraindo metade da lineHeight do meio da tela (screenHeight / 2).
// 		Isso servira para posicionar a linha de inicio da parede corretamente na tela.
// 			E verificado se o resultado e menor que zero. Se for, e ajustado para zera para
// 		garantir que nao haja valores negativos.

// 			drawEnd e calculado somando metade da lineHeight ao meio da tela (sreenHeight / 2).
// 		Isso determina a linha de fim da parede.
// 			E verificado se o calculo ultrapassa a linha maxima de altura. Se sim, e ajustada
// 		para o valor maximo da altura.
// 	*/
// 	main->rayCast->drawStart = -main->rayCast->lineHeight / 2 + screenHeight / 2;
// 	if (main->rayCast->drawStart < 0)
// 		main->rayCast->drawStart = 0;
// 	main->rayCast->drawEnd = (main->rayCast->lineHeight / 2) + screenHeight / 2;
// 	if (main->rayCast->drawEnd >= screenHeight)
// 		main->rayCast->drawEnd = screenHeight - 1;
// }

void	my_mlx_pixel_put(t_image *imagem, int x, int y, int color)
{
	char	*dst;

	dst = imagem->addr + (y * imagem->line_length + x
			* (imagem->bpp / 8));
	*(unsigned int *)dst = color;
}

void	get_wallX(t_main *main)
{
	/*
				Calculo da coordenada onde o raio atinge a parede.

			Se o lado atingido pelo raio for 0(lado horizontal), entao a coordenada
		wallX sera calculada usando a posicao Y inicial do raio e distancia
		perpendicular a parede, multiplicada pela direcao do raio no eixo Y.
			Se o lado for 1(lado vertical), entao a coordenada wallX e calculada
		usando a posicao X inicial do raio e a distancia perpendicular a parede
		multiplicada pela direcao do raio no eixo X.

			Apos isso, wallX e normalizada subtraindo a parte inteira da coordenada WallX
		usando a funcao floor, para garantir que esteja no intervalo [0, 1];
	*/
	if (main->rayCast->side == 0)
		main->rayCast->wallX = main->rayCast->posY + main->rayCast->perpWallDist * main->rayCast->rayDirY;
	if (main->rayCast->side == 1)
		main->rayCast->wallX = main->rayCast->posX + main->rayCast->perpWallDist * main->rayCast->rayDirX;
	main->rayCast->wallX -= floor(main->rayCast->wallX);
}

void	ft_tex_projection_x(t_main *main)
{
	/*
				Projecao da textura

			tex_x e a coordenada da textura que sera usada para colorir o pixel
		em questao.
			Multiplicando wallX pela largura da textura dar-nos-a essa coordenada
		na textura.
			A subtracao em "main->rayCast->tex_x = texWidth - main->rayCast->tex_x - 1"
		e feita para corrigir possiveis inversoes ou distorcoes na textura.

			tex_step e o tamanho do passo que deve ser dado ao percorrer a textura
		verticalmente por pixel na parede. Isso e calculado dividindo a largura da
		textura pelo numero de pixels na altura da parede.

			tex_pos e a posicao inicial na textura ao longo do eixo vertical. Isso
		e calculado com baso na posicao inicial de desenho da parede para garantir que
		a textura seja alinhada corretamente com a altura da parede na tela.
	*/

	main->rayCast->tex_x = (int)(main->rayCast->wallX * (double)texWidth);
	main->rayCast->tex_x = texWidth - main->rayCast->tex_x - 1;
	main->rayCast->tex_step = 1.0 * texWidth / main->rayCast->lineHeight;
	main->rayCast->tex_pos = (main->rayCast->drawStart - screenHeight / 2
								+ main->rayCast->lineHeight / 2) * main->rayCast->tex_step;
}

void	ft_tex_projection_y(t_main *main)
{
	/*
			Tex_y e a coordenada Y na textura que corresponde a posicao vertical
		do pixel na parede.

			tex_pos representa a posicao vertical atual na textura, e (texHeight - 1)
		e usado como uma mascara para garantir que o valor de tex_y esteja dentro dos
		limites da altura da textura.

			O operador & e usado para aplicar essa mascara.

			tex_pos e convertido para inteiro.

			O resultado desta operacao e a coordenada Y na textura correspondente a
		posicao vertical do pixel na parede.

			tex_pos e o avanco vertical na textura para o proximo pixel na parede.
	*/

	main->rayCast->tex_y = (int)main->rayCast->tex_pos & (texHeight - 1);
	main->rayCast->tex_pos += main->rayCast->tex_step;
}

// void	ft_side_of_pixel(t_main *main)
// {
// 	if (main->rayCast->side == 1)
// 	{
// 		if (main->rayCast->rayDirY < 0)
// 			main->tex = main->n_tex;
// 		else
// 			main->tex = main->s_tex;
// 	}
// 	else
// 	{
// 		if (main->rayCast->rayDirX < 0)
// 			main->tex = main->w_tex;
// 		else
// 			main->tex = main->e_tex;
// 	}
// }

void	ft_floor_and_ceiling(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	y = x;
	while (x < screenWidth)
	{
		y = 0;
		while (y < (screenHeight / 2))
		{
			my_mlx_pixel_put(main->img, x, y, main->f_c->floor);
			y++;
		}
		while (y < (screenHeight - 1))
		{
			my_mlx_pixel_put(main->img, x, y, main->f_c->ceiling);
			y++;
		}
		x++;
	}
}

void	rayCasting(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_floor_and_ceiling(main);
	while (x < screenWidth)
	{
		rayFirstSteps(main, x);
		raySecondsSteps(main);
		get_wallX(main);
		ft_tex_projection_x(main);
		y = main->rayCast->drawStart;
		while (y < main->rayCast->drawEnd)
		{
			ft_tex_projection_y(main);
			if (x >= 0 && y >= 0 && main->rayCast->tex_x >= 0 && main->rayCast->tex_y >= 0)
			{
				main->rayCast->color = *(unsigned int *)((main->tex->addr + (main->rayCast->tex_y * main->tex->line_length)
										+ (main->rayCast->tex_x * main->tex->bpp / 8)));
				my_mlx_pixel_put(main->img, x, y, main->rayCast->color);
			}
			y++;
		}
		mlx_put_image_to_window(main->mlx, main->mlx_win, main->img->img, 0, 0);
		x++;
	}
}
