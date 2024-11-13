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

void	check_rect(void)
{
	int	i;

	i = 0;
	while (data()->map[i])
	{
		if (ft_strlen(data()->map[i]) == data()->height)
			err("Error: Map must be square!", 1);
		i++;
	}
}

void	check_char(int x, int y)
{
	while (++y < data()->height)
	{
		x = -1;
		while (data()->map[y][++x])
			check_help(x, y);
	}
	if (data()->n_player != 1)
		err("Error: Invalid number of players!", 1);
	if (data()->n_exit != 1)
		err("Error: Invalid number of exits!", 1);
	if (!data()->n_collectible)
		err("Error: Invalid number of collectibles!", 1);
}

void	check_walls(void)
{
	int	i;
	int	j;

	i = 0;
	while (data()->map[i])
	{
		if (data()->map[i][0] != '1' || data()->map[i][data()->width - 1] != '1')
			err("Error: Map must be surrounded by walls!", 1);
		i++;
	}
	j = 0;
	while (data()->map[0][j])
	{
		if (data()->map[0][j] != '1' || data()->map[data()->height - 1][j] != '1')
			err("Error: Map must be surrounded by walls!", 1);
		j++;
	}
}

void	check_path(int x, int y)
{
	if (data()->map_copy[y][x] == '1' || data()->map_copy[y][x] == 'L')
		return ;
	if (data()->map_copy[y][x] == 'C')
		data()->path_collectible++;
	if (data()->map_copy[y][x] == 'E')
		data()->n_exit--;
	data()->map_copy[y][x] = '1';
	check_path(x + 1, y);
	check_path(x - 1, y);
	check_path(x, y + 1);
	check_path(x, y - 1);
}

void	check_map(void)
{
	check_rect();
	check_walls();
	check_char(-1, -1);
	data()->tot_collectible = data()->n_collectible;
	check_path(data()->player_x, data()->player_y);
	if (data()->path_collectible != data()->n_collectible)
		err("Error: Could not find valid path,\
	 can't collect all collectibles!", 1);
	if (data()->n_exit != 0)
		err("Error: Could not find valid path, Exit is blocked!", 1);
}
