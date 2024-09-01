/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:57:20 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:15:13 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int	destroy_hook(void)
{
	err("Game closed\n", 1);

	return (0);
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

int	move_player(char c, int num)
{
	put(data()->img.empty, data()->player_x, data()->player_y); 
	data()->map[data()->player_y][data()->player_x] = '0';
	if (c == 'y')
		change_img_y(num);
	else
		change_img_x(num);
	data()->map[data()->player_y][data()->player_x] = 'P';
	return (1);
}

int	move(int keypress)
{
	if (keypress == KEY_W && check_move(\
	data()->map[data()->player_y - 1][data()->player_x]))
		return (move_player('y', -1));
	else if (keypress == KEY_D && check_move(\
	data()->map[data()->player_y][data()->player_x + 1]))
		return(move_player('x', 1));
	else if (keypress == KEY_A && check_move(\
	data()->map[data()->player_y][data()->player_x - 1]))
		return (move_player('x', -1));
	else if (keypress == KEY_S && check_move(\
	data()->map[data()->player_y + 1][data()->player_x]))
		return(move_player('y', 1));
	return (0);
}

int	movekey_hook(int keypress)
{
	//char	dir;

	//dir = 'w';
	//dir = move_enemy(vars, dir);
	data()->level = data()->n_collectible / data()->tot_collectible;
	if (keypress == KEY_ESC)
		err("exit", 1);
	if (move(keypress))
	{
		put(data()->img.wall, 0, 0);
		mlx_string_put(data()->mlx, data()->win_ptr, 5, 15, \
	0x00FF0000, ft_itoa(++data()->moves, 10, "0123456789"));
	}
	return (0);
}
