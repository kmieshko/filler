/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:14:48 by kmieshko          #+#    #+#             */
/*   Updated: 2018/08/30 12:14:49 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*ft_create_filler(void)
{
	t_filler	*filler;

	filler = (t_filler *)malloc(sizeof(t_filler));
	filler->map.arr = NULL;
	filler->token.arr = NULL;
	filler->map.h = 0;
	filler->map.w = 0;
	filler->token.h = 0;
	filler->token.w = 0;
	filler->en_pos.x = 0;
	filler->en_pos.y = 0;
	filler->pl_pos.x = 0;
	filler->pl_pos.y = 0;
	filler->final.x = 0;
	filler->final.y = 0;
	filler->en_count = 0;
	filler->pl_count = 0;
	filler->flag = 0;
	return (filler);
}

int			ft_create_player(t_filler *filler)
{
	char	*line;

	line = NULL;
	get_next_line_fast(0, &line);
	if (ft_strlen(line) > 10 && ft_strncmp(line, "$$$ exec p", 9) == 0)
	{
		if (line[10] == '1')
		{
			filler->pl_id = 'O';
			filler->en_id = 'X';
		}
		else if (line[10] == '2')
		{
			filler->pl_id = 'X';
			filler->en_id = 'O';
		}
		free(line);
		return (1);
	}
	if (line)
		free(line);
	return (0);
}
