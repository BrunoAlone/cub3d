/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:12:45 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/14 15:31:39 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
