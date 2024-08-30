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

void	player_assets(t_data *vars, void *mlx_ptr)
{
	vars->img.player_s = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_s.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_w = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_w.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_a = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_a.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_d = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_d.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_s2 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_s2.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_w2 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_w2.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_a2 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_a2.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_d2 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_d2.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_s3 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_s3.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_w3 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_w3.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_a3 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_a3.xpm", \
	&vars->img.width, &vars->img.height);
	vars->img.player_d3 = mlx_xpm_file_to_image(mlx_ptr, "xpm/slime_d3.xpm", \
	&vars->img.width, &vars->img.height);
}

void	load_map(int fd, t_data	*vars)
{
	char	*str;
	char	*lines;

	lines = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str || (++vars->height == 0))
			break ;
		if (lines)
			lines = ft_strjoin(lines, str);
		else
			lines = ft_substr(str, 0, ft_strlen(str));
		free(str);
	}
	close (fd);
	if (!lines)
		err(vars, "Error: Map not valid!");
	vars->map = ft_split(lines, '\n');
	vars->map_copy = ft_split(lines, '\n');
	free(lines);
	if (!vars->map)
		err(vars, "Error: Map does not exist!");
	vars->width = ft_strlen(vars->map[0]);
}

void	put_map_to_window(t_data *v, int i, t_img img, void *win)
{
	int	j;

	while (v->map[i])
	{
		j = 0;
		while (v->map[i][j])
		{
			if (v->map[i][j] == '1')
				mlx_put_image_to_window(v->mlx, win, img.wall, 64 * j, 64 * i);
			if (v->map[i][j] == '0')
				mlx_put_image_to_window(v->mlx, win, img.empty, 64 * j, 64 * i);
			if (v->map[i][j] == 'C')
				mlx_put_image_to_window(v->mlx, win, \
			img.collectible, 64 * j, 64 * i);
			if (v->map[i][j] == 'E')
				mlx_put_image_to_window(v->mlx, win, img.exit, 64 * j, 64 * i);
			if (v->map[i][j] == 'P')
				mlx_put_image_to_window(v->mlx, win, \
			img.player_w, 64 * j, 64 * i);
			if (v->map[i][j] == 'L')
				mlx_put_image_to_window(v->mlx, win, img.enemy, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

int	check_arg(t_data	*vars, int argc, char *argv[])
{
	char	*str;
	int		i;
	int		fd;

	if (argc != 2 || ft_strlen(argv[1]) < 5)
		err(vars, "Error: Invalid input.\n");
	i = ft_strlen(argv[1]);
	str = ft_substr(argv[1], i - 4, 4);
	if (ft_strncmp(".ber", str, 4) != 0)
	{
		free(str);
		err(vars, "Error: File needs to be '.ber' .\n");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err(vars, "Error: Map does not open!");
	free(str);
	return (fd);
}

int	main(int argc, char **argv)
{
	static t_data	vars;

	load_map(check_arg(&vars, argc, argv), &vars);
	check_map(&vars);
	vars.mlx = mlx_init();
	vars.win_ptr = \
	mlx_new_window(vars.mlx, vars.width * 64, vars.height * 64, "So long!");
	if (!vars.mlx || !vars.win_ptr)
		err(&vars, "Init");
	assets(&vars, vars.mlx);
	player_assets(&vars, vars.mlx);
	put_map_to_window(&vars, 0, vars.img, vars.win_ptr);
	mlx_hook(vars.win_ptr, 17, 0, destroy_hook, &vars);
	mlx_key_hook(vars.win_ptr, movekey_hook, &vars);
	mlx_loop(vars.mlx);
}
