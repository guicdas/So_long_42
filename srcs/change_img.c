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

#include "includes/solong.h"

static void	put_player_img(t_player p_img)
{
	if (data()->level > 0.3f)
		put(p_img.lvl_1, data()->player_x, data()->player_y);
	else if (data()->level > 0.6f)
		put(p_img.lvl_2, data()->player_x, data()->player_y);
	else
		put(p_img.lvl_3, data()->player_x, data()->player_y);
}

void	change_img_y(int dir)
{
	data()->player_y += dir;
	if (dir < 0)
		put_player_img(data()->img.player_w);
	else
		put_player_img(data()->img.player_s);
}

void	change_img_x(int dir)
{
	data()->player_x += dir;
	if (dir < 0)
		put_player_img(data()->img.player_a);
	else
		put_player_img(data()->img.player_d);
}
