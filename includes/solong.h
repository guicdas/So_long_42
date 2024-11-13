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
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line.h"

# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	void	*player_w2;
	void	*player_a2;
	void	*player_s2;
	void	*player_d2;
	void	*player_w3;
	void	*player_a3;
	void	*player_s3;
	void	*player_d3;
	void	*enemy;
	int		height;
	int		width;
}t_img;

typedef struct s_data
{
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
int		mouse_hook(int button, int x, int y);
int		destroy_hook(void);
int		key_hook(int keycode);
int		movekey_hook(int keypress);

//-----	LIBFT	-----//
int		wordnum(char *s, char c);
int		wordlen(char *s, char c);
char	*word(char *s, char c);
char	*ft_itoa(long long n, int bs, char *b);
char	**ft_split(char *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

//-----	UTILS	-----//
void	put(void *img, int x, int y);
void	assets(void);
void	check_help(int x, int y);
void	print_map(char **map);

void	put_player_w(int x, int y);
void	put_player_a(int x, int y);
void	put_player_s(int x, int y);
void	put_player_d(int x, int y);

//-----	MAP		-----//
void	check_map(void);
int		check_move(char c);
char	move_enemy(char dir);

//-----	ENEMY	-----//
char	change_enemy(char dir, int num);

//-----	CHANGE	-----//
void	change_img_y(int dir);
void	change_img_x(int dir);

//-----	DESTROY	-----//
int		free_map(char **map);
void	err(char *msg, int code);
void	destroy_player_img(void);

//-----	PLAYER	-----//