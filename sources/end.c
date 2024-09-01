/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:16:38 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:14:10 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

int	free_map(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return (1);
	while (map[++i])
		free(map[i]);
	free(map);
	return (1);
}

void	destroy_player_img(void)
{
	mlx_destroy_image(data()->mlx, data()->img.player_w);
	mlx_destroy_image(data()->mlx, data()->img.player_s);
	mlx_destroy_image(data()->mlx, data()->img.player_a);
	mlx_destroy_image(data()->mlx, data()->img.player_d);
	mlx_destroy_image(data()->mlx, data()->img.player_w2);
	mlx_destroy_image(data()->mlx, data()->img.player_s2);
	mlx_destroy_image(data()->mlx, data()->img.player_a2);
	mlx_destroy_image(data()->mlx, data()->img.player_d2);
	mlx_destroy_image(data()->mlx, data()->img.player_w3);
	mlx_destroy_image(data()->mlx, data()->img.player_s3);
	mlx_destroy_image(data()->mlx, data()->img.player_a3);
	mlx_destroy_image(data()->mlx, data()->img.player_d3);
}

void	err(char *msg, int code)
{
	free_map(data()->map);
	free_map(data()->map_copy);
	if (data()->mlx)
	{
		destroy_player_img();
		mlx_destroy_image(data()->mlx, data()->img.enemy);
		mlx_destroy_image(data()->mlx, data()->img.collectible);
		mlx_destroy_image(data()->mlx, data()->img.exit);
		mlx_destroy_image(data()->mlx, data()->img.wall);
		mlx_destroy_image(data()->mlx, data()->img.empty);
		mlx_destroy_window(data()->mlx, data()->win_ptr);
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	ft_printf("%s\n", msg);
	exit(code);
}

void	print_map(char **map)
{
	int	i = -1, j;

	if (!map)
		err("deu merda", 1);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			printf("%c", map[i][j]);
		printf("\n");
	}
}
