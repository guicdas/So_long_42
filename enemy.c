/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:55:06 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:00:29 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	change_enemy(t_data *vars, char dir, int num)
{
	if (check_move(vars->map[vars->enemy_y - num][vars->enemy_x], vars))
	{
		vars->enemy_y -= num;
		put(vars, vars->img.enemy, vars->enemy_x, vars->enemy_y);
	}
	else
	{
		vars->enemy_y += num;
		put(vars, vars->img.enemy, vars->enemy_x, vars->enemy_y);
		vars->map[vars->enemy_y][vars->enemy_x] = 'L';
		if (dir == 'w')
			return ('s');
		else
			return ('w');
	}
	return (dir);
}

char	move_enemy(t_data *vars, char dir)
{
	put(vars, vars->img.empty, vars->enemy_x, vars->enemy_y); 
	vars->map[vars->enemy_y][vars->enemy_x] = '0';
	if (dir == 'w')
		dir = change_enemy(vars, dir, 1);
	else 
		dir = change_enemy(vars, dir, -1);
	vars->map[vars->enemy_y][vars->enemy_x] = 'L';
	return (dir);
}
