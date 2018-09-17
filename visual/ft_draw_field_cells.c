/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_field_cells.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:15:58 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/13 19:15:59 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		ft_draw_cells(int cell_size, t_mlx *mlx, t_color *color)
{
	t_coord	c;
	int		wide_y;

	c.y = 0;
	wide_y = 0;
	cell_size = cell_size * 4;
	while (c.y < cell_size)
	{
		c.x = 0;
		while (c.x < cell_size)
		{
			ft_pixel_put(mlx, color, wide_y, c.x);
			c.x = c.x + 4;
		}
		c.y = c.y + 4;
		wide_y = wide_y + (mlx->width * 4);
	}
}

static int	ft_get_field_height(t_mlx *mlx)
{
	int		height;

	height = 0;
	if (mlx->map.h < 20)
		height = (mlx->width / (1.2 * mlx->map.w)) * mlx->map.h;
	else if (mlx->map.h >= 20 && mlx->map.h < 40)
		height = (mlx->width / (1.2 * mlx->map.w)) * mlx->map.h - 14;
	else if (mlx->map.h >= 40)
		height = (mlx->width / (1.2 * mlx->map.w)) * mlx->map.h - 70;
	return (height);
}

static int	ft_get_field_width(t_mlx *mlx)
{
	int		width;

	width = 0;
	if (mlx->map.h < 20)
		width = (mlx->width / (1.2 * mlx->map.w)) * mlx->map.w;
	else if (mlx->map.h >= 20 && mlx->map.h < 40)
		width = (mlx->width / (1.2 * mlx->map.w)) * mlx->map.w - 24;
	else if (mlx->map.h >= 40)
		width = (mlx->width / (1.2 * mlx->map.w)) * mlx->map.w - 70;
	return (width);
}

void		ft_draw_field(t_mlx *mlx, t_color *color)
{
	t_coord	c;
	int		wide_y;
	int		height;
	int		width;

	wide_y = 0;
	height = ft_get_field_height(mlx);
	width = ft_get_field_width(mlx);
	c.y = 0;
	while (c.y < height * 4)
	{
		c.x = 0;
		while (c.x < width * 4)
		{
			ft_pixel_put(mlx, color, wide_y, c.x);
			c.x = c.x + 4;
		}
		c.y = c.y + 4;
		wide_y = wide_y + (mlx->width * 4);
	}
}
