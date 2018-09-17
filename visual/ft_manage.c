/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:42:55 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/14 13:42:58 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int	ft_manage(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	if (key == 8)
		mlx->init_color = -mlx->init_color;
	if (key == 49)
		mlx->stop = -mlx->stop;
	if (key == 37)
		system("leaks visual");
	ft_loop(mlx);
	return (0);
}

int	ft_exit_mouse(void)
{
	exit(0);
	return (0);
}
