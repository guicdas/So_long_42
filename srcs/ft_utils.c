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

t_data	*data(void){
	static t_data	d;

	return (&d);
}

void	put(void *img, int x, int y)
{
	mlx_put_image_to_window(data()->mlx, data()->win_ptr, img, 64 * x, 64 * y);
}

int	*xpm_to_image(char  *filename)
{
	return (mlx_xpm_file_to_image(data()->mlx, filename, &data()->img.width, &data()->img.height));
}

void	check_help(int x, int y)
{
	if (data()->map[y][x] == 'C')
		data()->n_collectible++;
	else if (data()->map[y][x] == 'E')
		data()->n_exit++;
	else if (data()->map[y][x] == 'L')
	{
		data()->n_enemy++;
		data()->enemy_x = x;
		data()->enemy_y = y;
	}
	else if (data()->map[y][x] == 'P')
	{
		data()->player_x = x;
		data()->player_y = y;
		data()->n_player++;
	}
	else if (data()->map[y][x] != '1' && data()->map[y][x] != '0')
		err("Error: Invalid character in map!", 1);
}

int	check_move(char c)
{
	if (c == '0' || c == 'C')
	{
		data()->n_collectible -= (c == 'C');
		return (1);
	}
	if (c == 'E' && !data()->n_collectible)
		err("CONGRATS YOU FINISHED THE GAME!", 0);
	if (c == 'L')
		err("YOU DIED!", 1);
	return (0);
}
