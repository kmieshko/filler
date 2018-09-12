/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:30:02 by kmieshko          #+#    #+#             */
/*   Updated: 2018/08/30 12:30:03 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_find_pos(t_filler *filler)
{
	t_coord	c;

	c.y = 0;
	while (c.y < filler->map.h)
	{
		c.x = 0;
		while (c.x < filler->map.w)
		{
			if (filler->map.arr[c.y][c.x] == filler->en_id)
				filler->en_pos = c;
			if (filler->map.arr[c.y][c.x] == filler->pl_id)
				filler->pl_pos = c;
			c.x++;
		}
		c.y++;
	}
	filler->flag = 1;
}

static void	ft_map_token_size(t_filler *filler, const char *arr, char *line)
{
	const char	*str1 = "Plateau ";
	const char	*str2 = "Piece ";

	if (ft_strcmp(str1, arr) == 0)
	{
		filler->map.h = ft_atoi(line + ft_strlen(arr));
		filler->map.w = ft_atoi(line + ft_strlen(arr) + 1 +
			ft_nb_len(filler->map.h));
	}
	else if (ft_strcmp(str2, arr) == 0)
	{
		filler->token.h = ft_atoi(line + ft_strlen(arr));
		filler->token.w = ft_atoi(line + ft_strlen(arr) + 1 +
			ft_nb_len(filler->token.h));
	}
}

void		ft_read_map(char *line, t_filler *filler)
{
	int			i;
	const char	*arr = "Plateau ";

	i = 0;
	if (filler->map.arr)
	{
		while (i < filler->map.h)
		{
			if (filler->map.arr[i] - 4)
				free(filler->map.arr[i] - 4);
			i++;
		}
		ft_memdel((void **)&filler->map.arr);
		i = 0;
	}
	ft_map_token_size(filler, arr, line);
	get_next_line_fast(0, &line);
	free(line);
	filler->map.arr = (char **)malloc(sizeof(char *) * (filler->map.h + 1));
	while (i < filler->map.h)
	{
		get_next_line_fast(0, &line);
		filler->map.arr[i] = line + 4;
		i++;
	}
}

static void	ft_find_token_start(t_filler *filler)
{
	t_coord	t;

	filler->start.x = filler->token.w;
	filler->start.y = filler->token.h;
	t.y = 0;
	while (t.y < filler->token.h)
	{
		t.x = 0;
		while (t.x < filler->token.w)
		{
			if (filler->token.arr[t.y][t.x] == '*')
			{
				if (t.x < filler->start.x)
					filler->start.x = t.x;
				if (t.y < filler->start.y)
					filler->start.y = t.y;
			}
			t.x++;
		}
		t.y++;
	}
}

void		ft_read_token(char *line, t_filler *filler)
{
	int			i;
	const char	*arr = "Piece ";

	i = 0;
	if (filler->token.arr)
	{
		while (i < filler->token.h)
		{
			if (filler->token.arr[i])
				free(filler->token.arr[i]);
			i++;
		}
		ft_memdel((void **)&filler->token.arr);
		i = 0;
	}
	ft_map_token_size(filler, arr, line);
	filler->token.arr = (char **)malloc(sizeof(char *) *
		(filler->token.h + 1));
	while (i < filler->token.h)
	{
		get_next_line_fast(0, &line);
		filler->token.arr[i] = line;
		i++;
	}
	ft_find_token_start(filler);
}
