/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:26:56 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/03 16:26:57 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_print_res(t_filler *filler)
{
	ft_putnbr(filler->final.y);
	ft_putchar(' ');
	ft_putnbr(filler->final.x);
	ft_putchar('\n');
}

void		ft_main_loop(t_filler *filler)
{
	char	*line;

	while (get_next_line_fast(0, &line))
	{
		if (!ft_strncmp(line, "Plateau ", 7))
		{
			ft_read_map(line, filler);
			if (filler->flag == 0)
				ft_find_pos(filler);
		}
		else if (!ft_strncmp(line, "Piece ", 5))
		{
			ft_read_token(line, filler);
			if (filler->map.h >= 20)
				ft_big_map(filler);
			else if (filler->map.h < 20)
				ft_small_map(filler);
			ft_print_res(filler);
		}
		ft_strdel(&line);
	}
}

int			main(void)
{
	t_filler	*filler;

	filler = ft_create_filler();
	if (ft_create_player(filler))
		ft_main_loop(filler);
	free(filler);
	return (0);
}
