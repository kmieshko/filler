/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:38:16 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/12 17:38:19 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "../incl/filler.h"
# include <mlx.h>
# define MLX mlx_string_put

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	char		pl_id;
	char		en_id;
	int			pl_count;
	int			en_count;
	char		*pl_name;
	char		*en_name;
	int			pl_color1;
	int			pl_color2;
	int			en_color1;
	int			en_color2;
	int			empty_color;
	int			field_color;
	int			height;
	int			width;
	int			pl_init;
	int			en_init;
	t_figure	map;
	t_coord		pixel;
	int			init_color;
	int			stop;
}				t_mlx;

t_mlx			*ft_create_mlx(void);
void			ft_get_player(char *line, t_mlx *mlx);
void			ft_get_map(char *line, t_mlx *mlx);
void			ft_draw_map(t_mlx *mlx);
void			ft_draw_cells(int cell_size, t_mlx *mlx, t_color *color);
void			ft_draw_field(t_mlx *mlx, t_color *color);
void			ft_pixel_put(t_mlx *mlx, t_color *color, int wide_y,
				int wide_x);
void			ft_print_text(t_mlx *mlx);
int				ft_manage(int key, t_mlx *mlx);
int				ft_exit_mouse(void);
int				ft_loop(t_mlx *mlx);

#endif
