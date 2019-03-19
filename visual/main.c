/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:38:34 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/06 12:38:35 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_main_loop(t_mlx *mlx)
{
	char	*line;

	line = 0;
	while (get_next_line_fast(0, &line))
	{
		if (!ft_strncmp(line, "error:", 6))
			exit(0);
		if (mlx->pl_init == 0 || mlx->en_init == 0)
			ft_get_player(line, mlx);
		if (!ft_strncmp(line, "Plateau ", 7))
			ft_get_map(line, mlx);
		if (!ft_strncmp(line, "Piece ", 5))
		{
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	ft_get_points(t_mlx *mlx)
{
	t_coord	c;

	mlx->pl_count = 0;
	mlx->en_count = 0;
	c.y = 0;
	while (c.y < mlx->map.h)
	{
		c.x = 0;
		while (c.x < mlx->map.w)
		{
			if (mlx->map.arr[c.y][c.x] == mlx->pl_id ||
				mlx->map.arr[c.y][c.x] == mlx->pl_id + 32)
				mlx->pl_count++;
			else if (mlx->map.arr[c.y][c.x] == mlx->en_id ||
				mlx->map.arr[c.y][c.x] == mlx->en_id + 32)
				mlx->en_count++;
			c.x++;
		}
		c.y++;
	}
}

int		ft_loop(t_mlx *mlx)
{
	if (mlx->stop < 0)
	{
		mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
		mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp),
			&(mlx->size_line), &(mlx->endian));
		ft_main_loop(mlx);
		ft_get_points(mlx);
		ft_draw_map(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		ft_print_text(mlx);
		mlx_destroy_image(mlx->mlx, mlx->img);
	}
	else if (mlx->stop > 0)
		MLX(mlx->mlx, mlx->win, mlx->width / 2 - 50,
			mlx->height / 10, 0xffffff, "STOP");
	return (0);
}

int		main(void)
{
	t_mlx	*mlx;

	mlx = ft_create_mlx();
	if (!(mlx->mlx = mlx_init()))
		return (0);
	system("afplay ./filler.wav&");
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "Filler");
	mlx_hook(mlx->win, 2, 5, ft_manage, mlx);
	mlx_loop_hook(mlx->mlx, ft_loop, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, ft_exit_mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
