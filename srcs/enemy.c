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

#include "includes/solong.h"

char	change_enemy(char dir, int num)
{
	if (check_move(data()->map[data()->enemy_y - num][data()->enemy_x]))
	{
		data()->enemy_y -= num;
		put(data()->img.enemy, data()->enemy_x, data()->enemy_y);
	}
	else
	{
		data()->enemy_y += num;
		put(data()->img.enemy, data()->enemy_x, data()->enemy_y);
		data()->map[data()->enemy_y][data()->enemy_x] = 'L';
		if (dir == 'w')
			return ('s');
		else
			return ('w');
	}
	return (dir);
}

char	move_enemy(char dir)
{
	put(data()->img.empty, data()->enemy_x, data()->enemy_y); 
	data()->map[data()->enemy_y][data()->enemy_x] = '0';
	if (dir == 'w')
		dir = change_enemy(dir, 1);
	else 
		dir = change_enemy(dir, -1);
	data()->map[data()->enemy_y][data()->enemy_x] = 'L';
	return (dir);
}
