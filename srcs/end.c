/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:16:38 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:14:10 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int	free_map(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return (1);
	while (map[++i])
		free(map[i]);
	free(map);
	return (1);
}

void	destroy_player_img(t_data *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.player_w);
	mlx_destroy_image(vars->mlx, vars->img.player_s);
	mlx_destroy_image(vars->mlx, vars->img.player_a);
	mlx_destroy_image(vars->mlx, vars->img.player_d);
	mlx_destroy_image(vars->mlx, vars->img.player_w2);
	mlx_destroy_image(vars->mlx, vars->img.player_s2);
	mlx_destroy_image(vars->mlx, vars->img.player_a2);
	mlx_destroy_image(vars->mlx, vars->img.player_d2);
	mlx_destroy_image(vars->mlx, vars->img.player_w3);
	mlx_destroy_image(vars->mlx, vars->img.player_s3);
	mlx_destroy_image(vars->mlx, vars->img.player_a3);
	mlx_destroy_image(vars->mlx, vars->img.player_d3);
}

void	err(t_data *vars, char *msg)
{
	free_map(vars->map);
	free_map(vars->map_copy);
	if (vars->mlx)
	{
		destroy_player_img(vars);
		mlx_destroy_image(vars->mlx, vars->img.enemy);
		mlx_destroy_image(vars->mlx, vars->img.collectible);
		mlx_destroy_image(vars->mlx, vars->img.exit);
		mlx_destroy_image(vars->mlx, vars->img.wall);
		mlx_destroy_image(vars->mlx, vars->img.empty);
		mlx_destroy_window(vars->mlx, vars->win_ptr);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	ft_printf("%s\n", msg);
	exit(1);
}

void	finish(t_data *vars)
{
	free_map(vars->map);
	free_map(vars->map_copy);
	if (vars->mlx)
	{
		destroy_player_img(vars);
		mlx_destroy_image(vars->mlx, vars->img.enemy);
		mlx_destroy_image(vars->mlx, vars->img.collectible);
		mlx_destroy_image(vars->mlx, vars->img.exit);
		mlx_destroy_image(vars->mlx, vars->img.wall);
		mlx_destroy_image(vars->mlx, vars->img.empty);
		mlx_destroy_window(vars->mlx, vars->win_ptr);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	ft_printf("CONGRATS! You finished the game with %d moves!!\n", vars->moves);
	exit(1);
}
