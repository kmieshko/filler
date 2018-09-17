/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:31:56 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/13 19:31:57 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_mlx_color(t_mlx *mlx)
{
	mlx->pl_color1 = 0x8500e8;
	mlx->pl_color2 = 0xa936ff;
	mlx->en_color1 = 0xffd633;
	mlx->en_color2 = 0xffe580;
	mlx->empty_color = 0x303030;
	mlx->field_color = 0x7f7f7f;
}

t_mlx		*ft_create_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bpp = 0;
	mlx->size_line = 0;
	mlx->endian = 0;
	mlx->pl_id = 0;
	mlx->en_id = 0;
	mlx->pl_name = NULL;
	mlx->en_name = NULL;
	mlx->height = 800;
	mlx->width = 800;
	mlx->pl_init = 0;
	mlx->en_init = 0;
	mlx->init_color = 1;
	mlx->stop = -1;
	ft_mlx_color(mlx);
	return (mlx);
}

void		ft_get_player(char *line, t_mlx *mlx)
{
	int		dot_pos;

	dot_pos = 0;
	if (!ft_strncmp(line, "$$$ exec p1 :", 13))
	{
		mlx->pl_id = 'O';
		mlx->en_id = 'X';
		dot_pos = ft_strchr_pos(line, '.');
		mlx->pl_name = ft_strsub(line, 23, dot_pos - 23);
		mlx->pl_init = 1;
	}
	else if (!ft_strncmp(line, "$$$ exec p2 :", 13))
	{
		if (mlx->pl_init == 0)
		{
			mlx->pl_id = 'X';
			mlx->en_id = 'O';
		}
		dot_pos = ft_strchr_pos(line, '.');
		mlx->en_name = ft_strsub(line, 23, dot_pos - 23);
		mlx->en_init = 1;
	}
}

static void	ft_map_hw(char *line, t_mlx *mlx)
{
	mlx->map.h = ft_atoi(line + ft_strlen("Plateau "));
	mlx->map.w = ft_atoi(line + ft_strlen("Plateau ") + 1 +
		ft_nb_len(mlx->map.h));
}

void		ft_get_map(char *line, t_mlx *mlx)
{
	int		i;
	char	*tmp;

	i = 0;
	if (mlx->map.arr)
	{
		while (i < mlx->map.h)
		{
			tmp = mlx->map.arr[i] - 4;
			ft_strdel(&tmp);
			i++;
		}
		ft_memdel((void **)&mlx->map.arr);
		i = 0;
	}
	ft_map_hw(line, mlx);
	get_next_line_fast(0, &line);
	ft_strdel(&line);
	mlx->map.arr = (char **)malloc(sizeof(char *) * (mlx->map.h + 1));
	while (i < mlx->map.h)
	{
		get_next_line_fast(0, &line);
		mlx->map.arr[i] = line + 4;
		i++;
	}
}
