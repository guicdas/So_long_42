/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:18:17 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 16:58:19 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void	check_rect(t_data *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (ft_strlen(vars->map[i]) == vars->height)
			err(vars, "Error: Map must be square!");
		i++;
	}
}

void	check_char(t_data *vars, int x, int y)
{
	while (++y < vars->height)
	{
		x = -1;
		while (vars->map[y][++x])
			check_help(vars, x, y);
	}
	if (vars->n_player != 1)
		err(vars, "Error: Invalid number of players!");
	if (vars->n_exit != 1)
		err(vars, "Error: Invalid number of exits!");
	if (!vars->n_collectible)
		err(vars, "Error: Invalid number of collectibles!");
}

void	check_walls(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
			err(vars, "Error: Map must be surrounded by walls!");
		i++;
	}
	j = 0;
	while (vars->map[0][j])
	{
		if (vars->map[0][j] != '1' || vars->map[vars->height - 1][j] != '1')
			err(vars, "Error: Map must be surrounded by walls!");
		j++;
	}
}

void	check_path(t_data *vars, int x, int y)
{
	if (vars->map_copy[y][x] == '1' || vars->map_copy[y][x] == 'L')
		return ;
	if (vars->map_copy[y][x] == 'C')
		vars->path_collectible++;
	if (vars->map_copy[y][x] == 'E')
		vars->n_exit--;
	vars->map_copy[y][x] = '1';
	check_path(vars, x + 1, y);
	check_path(vars, x - 1, y);
	check_path(vars, x, y + 1);
	check_path(vars, x, y - 1);
}

void	check_map(t_data *vars)
{
	check_rect(vars);
	check_walls(vars);
	check_char(vars, -1, -1);
	vars->tot_collectible = vars->n_collectible;
	check_path(vars, vars->player_x, vars->player_y);
	if (vars->path_collectible != vars->n_collectible)
		err(vars, "Error: Could not find valid path,\
	 can't collect all collectibles!");
	if (vars->n_exit != 0)
		err(vars, "Error: Could not find valid path, Exit is blocked!");
}
