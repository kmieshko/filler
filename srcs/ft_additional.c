/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:23:10 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/04 17:23:11 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	ft_nb_len(int nb)
{
	int		count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_manhattan_distance(t_filler *filler, int cur_pl, int cur_en)
{
	int		res;

	res = ft_abs(filler->pl_coord[cur_pl].x - filler->en_coord[cur_en].x)
		+ ft_abs(filler->pl_coord[cur_pl].y - filler->en_coord[cur_en].y);
	return (res);
}
