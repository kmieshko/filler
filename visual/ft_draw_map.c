/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:02:12 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/13 19:02:14 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_get_color(t_color *color, int c)
{
	color->r = (c & 0xff);
	color->g = ((c >> 8) & 0xff);
	color->b = ((c >> 16) & 0xff);
}

static void	ft_choose_color(t_coord c, t_color *color, t_mlx *mlx)
{
	if (mlx->init_color > 0)
	{
		mlx->pl_color1 = 0x8500e8;
		mlx->pl_color2 = 0xa936ff;
		mlx->en_color1 = 0xffd633;
		mlx->en_color2 = 0xffe580;
	}
	else if (mlx->init_color < 0)
	{
		mlx->pl_color1 = 0x4f9aa8;
		mlx->pl_color2 = 0x80b9c3;
		mlx->en_color1 = 0xb67d78;
		mlx->en_color2 = 0xd1adaa;
	}
	if (mlx->map.arr[c.y][c.x] == '.')
		ft_get_color(color, mlx->empty_color);
	else if (mlx->map.arr[c.y][c.x] == mlx->pl_id)
		ft_get_color(color, mlx->pl_color1);
	else if (mlx->map.arr[c.y][c.x] == mlx->pl_id + 32)
		ft_get_color(color, mlx->pl_color2);
	else if (mlx->map.arr[c.y][c.x] == mlx->en_id)
		ft_get_color(color, mlx->en_color1);
	else if (mlx->map.arr[c.y][c.x] == mlx->en_id + 32)
		ft_get_color(color, mlx->en_color2);
}

static void	ft_choose_field(t_color *color, t_mlx *mlx)
{
	if (mlx->map.h < 20)
	{
		mlx->pixel.x = mlx->width / 12 - 2;
		mlx->pixel.y = mlx->height / 5;
		ft_draw_field(mlx, color);
	}
	else if (mlx->map.h >= 20 && mlx->map.h < 40)
	{
		mlx->pixel.x = mlx->width / 10 - 2;
		mlx->pixel.y = mlx->height / 3 - 2;
		ft_draw_field(mlx, color);
	}
	else if (mlx->map.h >= 40)
	{
		mlx->pixel.x = mlx->width / 8 - 2;
		mlx->pixel.y = mlx->height / 5 + 2;
		ft_draw_field(mlx, color);
	}
}

static void	ft_choose_pixel_put(t_coord c, int cell_size, t_mlx *mlx)
{
	if (mlx->map.h < 20)
	{
		mlx->pixel.x = (c.x * cell_size) + (c.x * 2) + mlx->width / 12;
		mlx->pixel.y = (c.y * cell_size) + (c.y * 2) +
			mlx->height / (0.25 * mlx->map.h) - mlx->height / 16;
	}
	else if (mlx->map.h >= 20 && mlx->map.h < 40)
	{
		mlx->pixel.x = (c.x * cell_size) + (c.x * 2) + mlx->width / 10;
		mlx->pixel.y = (c.y * cell_size) + (c.y * 2) +
			mlx->height / (0.25 * mlx->map.h) + mlx->height / 6;
	}
	else if (mlx->map.h >= 40)
	{
		mlx->pixel.x = (c.x * cell_size) + (c.x * 2) + mlx->width / 8;
		mlx->pixel.y = (c.y * cell_size) + (c.y * 2) +
			mlx->height / (0.25 * mlx->map.h) + mlx->height / 6;
	}
}

void		ft_draw_map(t_mlx *mlx)
{
	t_coord	c;
	t_color	*color;
	int		cell_size;

	color = (t_color *)malloc(sizeof(t_color));
	mlx->pixel.x = 0;
	mlx->pixel.y = 0;
	ft_get_color(color, mlx->field_color);
	ft_choose_field(color, mlx);
	cell_size = (mlx->width / (1.2 * mlx->map.w)) - 2;
	c.y = 0;
	while (c.y < mlx->map.h)
	{
		c.x = 0;
		while (c.x < mlx->map.w)
		{
			ft_choose_color(c, color, mlx);
			ft_choose_pixel_put(c, cell_size, mlx);
			ft_draw_cells(cell_size, mlx, color);
			c.x++;
		}
		c.y++;
	}
	ft_memdel((void **)&color);
}
