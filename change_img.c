/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:15:05 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 16:56:11 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	change_img(t_data *vars, char c, int dir)
{
	put(vars, vars->img.empty, vars->player_x, vars->player_y); 
	vars->map[vars->player_y][vars->player_x] = '0';
	if (c == 'y')
	{
		vars->player_y += dir;
		if (dir < 0)
			put(vars, vars->img.player_w, vars->player_x, vars->player_y);
		else
			put(vars, vars->img.player_s, vars->player_x, vars->player_y);
	}
	if (c == 'x')
	{
		vars->player_x += dir;
		if (dir < 0)
			put(vars, vars->img.player_a, vars->player_x, vars->player_y);
		else
			put(vars, vars->img.player_d, vars->player_x, vars->player_y);
	}
	vars->map[vars->player_y][vars->player_x] = 'P';
}

void	change_img2(t_data *vars, char c, int dir)
{
	put(vars, vars->img.empty, vars->player_x, vars->player_y); 
	vars->map[vars->player_y][vars->player_x] = '0';
	if (c == 'y')
	{
		vars->player_y += dir;
		if (dir < 0)
			put(vars, vars->img.player_w2, vars->player_x, vars->player_y);
		else
			put(vars, vars->img.player_s2, vars->player_x, vars->player_y);
	}
	if (c == 'x')
	{
		vars->player_x += dir;
		if (dir < 0)
			put(vars, vars->img.player_a2, vars->player_x, vars->player_y);
		else
			put(vars, vars->img.player_d2, vars->player_x, vars->player_y);
	}
	vars->map[vars->player_y][vars->player_x] = 'P';
}

void	change_img3(t_data *vars, char c, int dir)
{
	put(vars, vars->img.empty, vars->player_x, vars->player_y); 
	vars->map[vars->player_y][vars->player_x] = '0';
	if (c == 'y')
	{
		vars->player_y += dir;
		if (dir < 0)
			put(vars, vars->img.player_w3, vars->player_x, vars->player_y);
		else
			put(vars, vars->img.player_s3, vars->player_x, vars->player_y);
	}
	if (c == 'x')
	{
		vars->player_x += dir;
		if (dir < 0)
			put(vars, vars->img.player_a3, vars->player_x, vars->player_y);
		else
			put(vars, vars->img.player_d3, vars->player_x, vars->player_y);
	}
	vars->map[vars->player_y][vars->player_x] = 'P';
}
