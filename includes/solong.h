/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes/solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:31:36 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:12:27 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line.h"

# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307

typedef struct s_player
{
	void	*lvl_1;
	void	*lvl_2;
	void	*lvl_3;
}t_player;

typedef struct s_img
{
	void		*empty;
	void		*wall;
	void		*collectible;
	void		*exit;
	t_player	player_w;
	t_player	player_a;
	t_player	player_s;
	t_player	player_d;
	void		*enemy;
	int			height;
	int			width;
}t_img;

typedef struct s_fps
{
	struct timeval	start_t;
	struct timeval	current_t;
	long	frames;
	long	last_frames;
	float	fps;
}t_fps;

typedef struct s_data
{
	t_fps	fps;
	t_img	img;
	void	*mlx;
	void	*win_ptr;
	char	*data;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		tot_collectible;
	int		n_collectible;
	int		path_collectible;
	int		n_exit;
	int		n_player;
	int		n_enemy;
	char	**map;
	char	**map_copy;
	int		moves;
	float	level;
}t_data;

t_data	*data(void);

//-----	HOOKS	-----//
int		destroy_hook(void);
int		movekey_hook(int keypress);
int		frame_hook(void);

//-----	LIBFT	-----//
char	**ft_split(char *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

//-----	UTILS	-----//
void	put(void *img, int x, int y);
int		*xpm_to_image(char  *filename);
void	print_map(char **map);
int		check_move(char c);

//-----	MAP		-----//
void	check_map(void);
void	check_help(int x, int y);

//-----	ENEMY	-----//
char	change_enemy(char dir, int num);
char	move_enemy(char dir);

//-----	CHANGE	-----//
void	change_img_y(int dir);
void	change_img_x(int dir);

//-----	DESTROY	-----//
int		free_map(char **map);
void	err(char *msg, int code);
void	destroy_player_img(void);
