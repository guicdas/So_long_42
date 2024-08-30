/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:33:56 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:14:54 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void	put(t_data *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
	img, 64 * x, 64 * y);
}

void	assets(t_data	*vars, void *mlx_ptr)
{
	vars->img.collectible = mlx_xpm_file_to_image(mlx_ptr, "xpm/XY_plane.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.exit = mlx_xpm_file_to_image(mlx_ptr, "xpm/open30.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.wall = mlx_xpm_file_to_image(mlx_ptr, "xpm/open24.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.empty = mlx_xpm_file_to_image(mlx_ptr, "xpm/floor.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.enemy = mlx_xpm_file_to_image(mlx_ptr, "xpm/open.xpm", \
	&vars->img.width, &vars->img.height);
}

void	check_help(t_data *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
		vars->n_collectible++;
	else if (vars->map[y][x] == 'E')
		vars->n_exit++;
	else if (vars->map[y][x] == 'L')
	{
		vars->n_enemy++;
		vars->enemy_x = x;
		vars->enemy_y = y;
	}
	else if (vars->map[y][x] == 'P')
	{
		vars->player_x = x;
		vars->player_y = y;
		vars->n_player++;
	}
	else if (vars->map[y][x] != '1' && vars->map[y][x] != '0')
		err(vars, "Error: Invalid character in map!");
}
