/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:32:04 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:15:26 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

static void	player_assets(void)
{
	data()->img.player_s.lvl_1 = xpm_to_image("textures/slime_s.xpm");
	data()->img.player_w.lvl_1 = xpm_to_image("textures/slime_w.xpm");
	data()->img.player_a.lvl_1 = xpm_to_image("textures/slime_a.xpm");
	data()->img.player_d.lvl_1 = xpm_to_image("textures/slime_d.xpm");
	data()->img.player_s.lvl_2 = xpm_to_image("textures/slime_s2.xpm");
	data()->img.player_w.lvl_2 = xpm_to_image("textures/slime_w2.xpm");
	data()->img.player_a.lvl_2 = xpm_to_image("textures/slime_a2.xpm");
	data()->img.player_d.lvl_2 = xpm_to_image("textures/slime_d2.xpm");
	data()->img.player_s.lvl_3 = xpm_to_image("textures/slime_s3.xpm");
	data()->img.player_w.lvl_3 = xpm_to_image("textures/slime_w3.xpm");
	data()->img.player_a.lvl_3 = xpm_to_image("textures/slime_a3.xpm");
	data()->img.player_d.lvl_3 = xpm_to_image("textures/slime_d3.xpm");
	data()->img.collectible = xpm_to_image("textures/XY_plane.xpm");
	data()->img.exit = xpm_to_image("textures/open30.xpm");
	data()->img.wall = xpm_to_image("textures/open24.xpm");
	data()->img.empty = xpm_to_image("textures/floor.xpm");
	data()->img.enemy = xpm_to_image("textures/open.xpm");
}

static void	load_map(int fd)
{
	char	*str;
	char	*lines;

	lines = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str || (++data()->height == 0))
			break ;
		if (lines)
			lines = ft_strjoin(lines, str);
		else
			lines = ft_substr(str, 0, ft_strlen(str));
		free(str);
	}
	close (fd);
	if (!lines)
		err("Error: Map not valid!", 1);
	data()->map = ft_split(lines, '\n');
	data()->map_copy = ft_split(lines, '\n');
	free(lines);
	if (!data()->map)
		err("Error: Map does not exist!", 1);
	data()->width = ft_strlen(data()->map[0]);
}

static void	put_map_to_window(void)
{
	int	i = 0, j;

	while (data()->map[i])
	{
		j = 0;
		while (data()->map[i][j])
		{
			if (data()->map[i][j] == '1')
				put(data()->img.wall, j, i);
			if (data()->map[i][j] == '0')
				put(data()->img.empty, j, i);
			if (data()->map[i][j] == 'C')
				put(data()->img.collectible, j, i);
			if (data()->map[i][j] == 'E')
				put(data()->img.exit, j, i);
			if (data()->map[i][j] == 'P')
				put(data()->img.player_w.lvl_1, j, i);
			if (data()->map[i][j] == 'L')
				put(data()->img.enemy, j, i);
			j++;
		}
		i++;
	}
}

static int	check_arg(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		fd;

	if (argc != 2 || ft_strlen(argv[1]) < 5)
		err("Error: Invalid input.\n", 1);
	i = ft_strlen(argv[1]);
	str = ft_substr(argv[1], i - 4, 4);
	if (ft_strncmp(".ber", str, 4) != 0)
	{
		free(str);
		err("Error: File needs to be '.ber' .\n", 1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err("Error: Map does not open!", 1);
	free(str);
	return (fd);
}

int	main(int argc, char **argv)
{
    gettimeofday(&data()->fps.start_t, NULL);

	load_map(check_arg(argc, argv));
	check_map();
	data()->mlx = mlx_init();
	data()->win_ptr = \
	mlx_new_window(data()->mlx, data()->width * 64, data()->height * 64, "So long!");
	if (!data()->mlx || !data()->win_ptr)
		err("Error: Couldn't initialize window!\n", 1);
	player_assets();
	put_map_to_window();
	mlx_hook(data()->win_ptr, 17, 0, destroy_hook, data());
	mlx_loop_hook(data()->mlx, frame_hook, &data);
	mlx_key_hook(data()->win_ptr, movekey_hook, data());
	mlx_loop(data()->mlx);
}
