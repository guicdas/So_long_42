/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:31:36 by gcatarin          #+#    #+#             */
/*   Updated: 2023/09/26 17:12:27 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

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
}t_data;

//--------HOOKS----///
int		mouse_hook(int button, int x, int y, t_data *vars);
int		destroy_hook(t_data *vars);
int		key_hook(int keycode, t_data *vars);
int		movekey_hook(int keypress, t_data *vars);
//----HELP-FUNCS----//
int		wordnum(char *s, char c);
int		wordlen(char *s, char c);
char	*word(char *s, char c);
char	*ft_itoa(long long n, int bs, char *b);
char	**ft_split(char *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
//-------UTILS------//
void	put(t_data *vars, void *img, int x, int y);
void	assets(t_data	*vars, void *mlx_ptr);
void	check_help(t_data *vars, int x, int y);
//--------MAP---------//
void	check_map(t_data *vars);
int		check_move(char c, t_data *vars);
char	move_enemy(t_data *vars, char dir);
//-------ENEMY-------//
char	change_enemy(t_data *vars, char dir, int num);
//-------CHANGE-------//
void	change_img(t_data *vars, char c, int dir);
void	change_img2(t_data *vars, char c, int dir);
void	change_img3(t_data *vars, char c, int dir);
//-------DESTROY------//
int		free_map(char **map);
void	err(t_data *vars, char *msg);
void	destroy_player_img(t_data *vars);
void	finish(t_data *vars);
#endif