/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:18:38 by kmieshko          #+#    #+#             */
/*   Updated: 2018/08/21 11:18:41 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_figure
{
	int			w;
	int			h;
	int			size;
	char		**arr;
}				t_figure;

typedef struct	s_filler
{
	t_figure	map;
	t_figure	token;
	t_coord		final;
	int			dist;
	t_coord		*pl_coord;
	t_coord		*en_coord;
	int			pl_count;
	int			en_count;
	char		pl_id;
	char		en_id;
	t_coord		pl_pos;
	t_coord		en_pos;
	int			flag;
	t_coord		start;
	int			count;
}				t_filler;

int				ft_abs(int nb);
int				ft_nb_len(int nb);
int				ft_manhattan_distance(t_filler *filler, int cur_pl, int cur_en);
t_filler		*ft_create_filler(void);
int				ft_create_player(t_filler *filler);
void			ft_find_pos(t_filler *filler);
void			ft_read_map(char *line, t_filler *filler);
void			ft_read_token(char *line, t_filler *filler);
int				ft_is_placeable(t_coord c, t_filler *filler);
void			ft_big_map(t_filler *filler);
void			ft_small_map(t_filler *filler);

int				ft_get_next_line(const int fd, char **line);

#endif
