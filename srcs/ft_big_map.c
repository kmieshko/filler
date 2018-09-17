/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:20:55 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/04 17:20:56 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_pl_en_count(t_filler *filler)
{
	t_coord	c;

	c.y = 0;
	while (c.y < filler->map.h)
	{
		c.x = 0;
		while (c.x < filler->map.w)
		{
			if (filler->map.arr[c.y][c.x] == filler->pl_id ||
				filler->map.arr[c.y][c.x] == filler->pl_id + 32)
			{
				filler->pl_coord[filler->pl_count] = c;
				filler->pl_count++;
			}
			if (filler->map.arr[c.y][c.x] == filler->en_id ||
				filler->map.arr[c.y][c.x] == filler->en_id + 32)
			{
				filler->en_coord[filler->en_count] = c;
				filler->en_count++;
			}
			c.x++;
		}
		c.y++;
	}
}

static int	ft_main_condition(t_coord p, t_coord t, t_filler *filler, int tmp)
{
	if (filler->token.arr[t.y][t.x] == '*')
	{
		if (p.x >= 0 && p.x < filler->map.w && p.y >= 0 && p.y < filler->map.h)
		{
			if (ft_is_placeable(p, filler))
			{
				filler->final = p;
				filler->dist = tmp;
				return (1);
			}
		}
	}
	return (0);
}

static void	ft_place_near_enemy(t_filler *filler, int tmp, t_coord c)
{
	t_coord		t;
	t_coord		p;

	p.x = 0;
	p.y = 0;
	t.y = filler->start.y;
	while (t.y < filler->token.h)
	{
		t.x = filler->start.x;
		while (t.x < filler->token.w)
		{
			p.x = c.x - t.x;
			p.y = c.y - t.y;
			if (ft_main_condition(p, t, filler, tmp))
				return ;
			t.x++;
		}
		t.y++;
	}
}

static void	ft_init_filler(t_filler *filler)
{
	filler->final.x = 0;
	filler->final.y = 0;
	filler->pl_count = 0;
	filler->en_count = 0;
	filler->dist = filler->map.h * filler->map.w;
	if (filler->pl_coord)
		ft_memdel((void **)&filler->pl_coord);
	if (filler->en_coord)
		ft_memdel((void **)&filler->en_coord);
	filler->pl_coord = (t_coord *)malloc(sizeof(t_coord) * filler->dist);
	filler->en_coord = (t_coord *)malloc(sizeof(t_coord) * filler->dist);
}

void		ft_big_map(t_filler *filler)
{
	t_coord	pl;
	int		tmp;

	ft_init_filler(filler);
	ft_pl_en_count(filler);
	pl.y = 0;
	while (pl.y < filler->pl_count)
	{
		pl.x = 0;
		while (pl.x < filler->en_count)
		{
			tmp = ft_manhattan_distance(filler, pl.y, pl.x);
			if (tmp <= filler->dist)
				ft_place_near_enemy(filler, tmp, filler->pl_coord[pl.y]);
			pl.x++;
		}
		pl.y++;
	}
}
