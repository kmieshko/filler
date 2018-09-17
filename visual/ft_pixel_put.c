/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:27:10 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/13 19:27:11 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_pixel_put(t_mlx *mlx, t_color *color, int wide_y, int wide_x)
{
	int		x;
	int		y;

	x = mlx->pixel.x;
	y = mlx->pixel.y;
	mlx->addr[wide_x + wide_y + y * mlx->size_line + 4 * x] = color->r;
	mlx->addr[wide_x + wide_y + y * mlx->size_line + 4 * x + 1] = color->g;
	mlx->addr[wide_x + wide_y + y * mlx->size_line + 4 * x + 2] = color->b;
}
