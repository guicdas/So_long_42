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

#include "solong.h"

int	destroy_hook(t_data *vars)
{
	err(vars, "\nexit");
	return (0);
}

int	check_move(char c, t_data *vars)
{
	if (c == '0' || c == 'C')
	{
		vars->n_collectible -= (c == 'C');
		return (1);
	}
	if (c == 'E' && !vars->n_collectible)
	{
		finish(vars);
		return (1);
	}
	if (c == 'L')
		err(vars, "YOU DIED!");
	return (0);
}

int	move_help(t_data *vars, char c, int num, int level)
{
	if (level > vars->tot_collectible * (2 * vars->tot_collectible / 3))
		change_img(vars, c, num);
	else if (level > vars->tot_collectible * (1 * vars->tot_collectible / 3))
		change_img2(vars, c, num);
	else
		change_img3(vars, c, num);
	return (1);
}

int	move(t_data *vars, int keypress)
{
	if (keypress == KEY_W && check_move(\
	vars->map[vars->player_y - 1][vars->player_x], vars))
	{
		move_help(vars, 'y', -1, (vars->tot_collectible * vars->n_collectible));
		return (1);
	}
	if (keypress == KEY_D && check_move(\
	vars->map[vars->player_y][vars->player_x + 1], vars))
	{
		move_help(vars, 'x', 1, (vars->tot_collectible * vars->n_collectible));
		return (1);
	}
	if (keypress == KEY_A && check_move(\
	vars->map[vars->player_y][vars->player_x - 1], vars))
	{
		move_help(vars, 'x', -1, (vars->tot_collectible * vars->n_collectible));
		return (1);
	}
	if (keypress == KEY_S && check_move(\
	vars->map[vars->player_y + 1][vars->player_x], vars))
	{
		move_help(vars, 'y', 1, (vars->tot_collectible * vars->n_collectible));
		return (1);
	}
	return (0);
}

int	movekey_hook(int keypress, t_data *vars)
{
	char	*str;
	char	dir;

	dir = 'w';
	dir = move_enemy(vars, dir);
	if (keypress == KEY_ESC)
		err(vars, "\nexit");
	if (move(vars, keypress))
	{
		str = ft_itoa(++vars->moves, 10, "0123456789");
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
	vars->img.wall, 1, 1);
		mlx_string_put(vars->mlx, vars->win_ptr, \
	5, 15, 0x00FF0000, str);
	}
	return (0);
}
