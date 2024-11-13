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

void	change_img_y(int dir)
{
	data()->player_y += dir;
	if (dir < 0)
		put_player_w(data()->player_x, data()->player_y);
	else
		put_player_s(data()->player_x, data()->player_y);
}

void	change_img_x(int dir)
{
	data()->player_x += dir;
	if (dir < 0)
		put_player_a(data()->player_x, data()->player_y);
	else
		put_player_d(data()->player_x, data()->player_y);
}
