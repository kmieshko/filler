/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:18:28 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/14 11:18:29 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_print_text2(t_mlx *mlx, char *score2)
{
	MLX(mlx->mlx, mlx->win, mlx->width / 1.5,
		mlx->height / 30 + 30, mlx->en_color1, "Player2:");
	MLX(mlx->mlx, mlx->win, mlx->width / 1.5 - 20,
		mlx->height / 30 + 60, 0x68e601, "Name:");
	MLX(mlx->mlx, mlx->win, mlx->width / 1.5 + 50,
		mlx->height / 30 + 60, mlx->en_color1, mlx->en_name);
	MLX(mlx->mlx, mlx->win, mlx->width / 1.5 - 20,
		mlx->height / 30 + 90, 0x68e601, "Score:");
	MLX(mlx->mlx, mlx->win, mlx->width / 1.5 + 50,
		mlx->height / 30 + 90, mlx->en_color1, score2);
}

void		ft_print_text(t_mlx *mlx)
{
	char	*score1;
	char	*score2;

	score1 = ft_itoa(mlx->pl_count);
	score2 = ft_itoa(mlx->en_count);
	MLX(mlx->mlx, mlx->win, mlx->width / 2 - 50,
		mlx->height / 100, 0xff9f00, "Filler");
	MLX(mlx->mlx, mlx->win, mlx->width / 50 + 75,
		mlx->height / 30 + 30, mlx->pl_color1, "Player1:");
	MLX(mlx->mlx, mlx->win, mlx->width / 50 + 50,
		mlx->height / 30 + 60, 0x68e601, "Name:");
	MLX(mlx->mlx, mlx->win, mlx->width / 50 + 120,
		mlx->height / 30 + 60, mlx->pl_color1, mlx->pl_name);
	MLX(mlx->mlx, mlx->win, mlx->width / 50 + 50,
		mlx->height / 30 + 90, 0x68e601, "Score:");
	MLX(mlx->mlx, mlx->win, mlx->width / 50 + 120,
		mlx->height / 30 + 90, mlx->pl_color1, score1);
	ft_print_text2(mlx, score2);
	ft_strdel(&score1);
	ft_strdel(&score2);
}
