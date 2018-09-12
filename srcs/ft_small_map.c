/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:15:59 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/04 17:16:01 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_small_down_left(t_filler *filler)
{
	t_coord	c;

	filler->final.x = 0;
	filler->final.y = 0;
	c.y = 0;
	while (c.y < filler->map.h)
	{
		c.x = filler->map.w - 1;
		while (c.x > 0)
		{
			if (ft_is_placeable(c, filler))
			{
				filler->final = c;
				return ;
			}
			c.x--;
		}
		c.y++;
	}
}

static void	ft_small_down_right(t_filler *filler)
{
	t_coord	c;

	filler->final.x = 0;
	filler->final.y = 0;
	c.y = 0;
	while (c.y < filler->map.h)
	{
		c.x = 0;
		while (c.x < filler->map.w)
		{
			if (ft_is_placeable(c, filler))
			{
				filler->final = c;
				return ;
			}
			c.x++;
		}
		c.y++;
	}
}

static void	ft_small_up_left(t_filler *filler)
{
	t_coord	c;

	filler->final.x = 0;
	filler->final.y = 0;
	c.y = filler->map.h - 1;
	while (c.y > 0)
	{
		c.x = filler->map.w - 1;
		while (c.x > 0)
		{
			if (ft_is_placeable(c, filler))
			{
				filler->final = c;
				return ;
			}
			c.x--;
		}
		c.y--;
	}
}

static void	ft_small_up_right(t_filler *filler)
{
	t_coord	c;

	filler->final.x = 0;
	filler->final.y = 0;
	c.y = filler->map.h - 1;
	while (c.y > 0)
	{
		c.x = 0;
		while (c.x < filler->map.w)
		{
			if (ft_is_placeable(c, filler))
			{
				filler->final = c;
				return ;
			}
			c.x++;
		}
		c.y--;
	}
}

void		ft_small_map(t_filler *filler)
{
	if (filler->pl_pos.y < filler->map.h / 2)
	{
		if (filler->pl_pos.x < filler->map.w / 2)
			ft_small_up_left(filler);
		else if (filler->pl_pos.x >= filler->map.w / 2)
			ft_small_up_right(filler);
	}
	else if (filler->pl_pos.y >= filler->map.h / 2)
	{
		if (filler->pl_pos.x < filler->map.w / 2)
			ft_small_down_left(filler);
		else if (filler->pl_pos.x >= filler->map.w / 2)
			ft_small_down_right(filler);
	}
	filler->pl_pos = filler->final;
}
