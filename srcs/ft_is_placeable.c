/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_placeable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:26:33 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/04 17:26:34 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_condition(t_coord t, t_coord c, t_filler *filler)
{
	if (filler->token.arr[t.y][t.x] == '*' &&
		(filler->map.arr[c.y + t.y][c.x + t.x] == filler->en_id ||
			filler->map.arr[c.y + t.y][c.x + t.x] == filler->en_id + 32))
	{
		return (0);
	}
	if (filler->token.arr[t.y][t.x] == '*' &&
		(filler->map.arr[c.y + t.y][c.x + t.x] == filler->pl_id ||
			filler->map.arr[c.y + t.y][c.x + t.x] == filler->pl_id + 32))
	{
		filler->count++;
		if (filler->count > 1)
			return (0);
	}
	return (1);
}

int			ft_is_placeable(t_coord c, t_filler *filler)
{
	t_coord	t;

	filler->count = 0;
	if (c.y + filler->token.h > filler->map.h ||
		c.x + filler->token.w > filler->map.w)
		return (0);
	t.y = filler->start.y;
	while (t.y < filler->token.h)
	{
		t.x = filler->start.x;
		while (t.x < filler->token.w)
		{
			if (!ft_condition(t, c, filler))
				return (0);
			t.x++;
		}
		t.y++;
	}
	if (filler->count == 1)
		return (1);
	return (0);
}
