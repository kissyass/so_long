/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:19:36 by ykissiko          #+#    #+#             */
/*   Updated: 2023/02/10 15:59:53 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_game
{
	int		player_num;
	int		player_x;
	int		player_y;
	int		player_past_x;
	int		player_past_y;
	int		exit_num;
	int		coin_num;
	int		moves;
	int		map_len;
	int		map_width;
	int		coin_num_check;
	int		exit_num_check;
	char	**map;
	char	**map_check;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background;
	void	*player_front;
	void	*player_back;
	void	*player_left;
	void	*player_right;
	void	*coin;
	void	*wall;
	void	*exit_door;
	void	*enemy;
}	t_game;

int		ft_check_input(int argc, char **argv);
int		ft_check_ext(char *file, int len, char *ext);
void	ft_init_map(char *map);
void	ft_init_param(t_game *game);
int		ft_read_map(t_game *game, char *map);
int		ft_set_image_1(t_game *game);
int		ft_set_image_2(t_game *game);
int		ft_check_map(t_game *game);
void	ft_set_map(t_game *game);
int		ft_action(int key, t_game *game);
void	ft_action_player(t_game *game);
int		ft_exit(t_game *game);
void	ft_check_move(t_game *game, int x, int y);
int		ft_check_map_obj(t_game *game);
int		ft_check_map_obj_2(t_game *game);
void	ft_check_path(t_game *game, int x, int y);
int		ft_check_rect(t_game *game);
void	ft_free_game(t_game *game, char **map);
int		ft_read_map_check(t_game *game, char *map);
void	ft_put_img(t_game *game, void *img, int x, int y);
void	ft_init_map_2(t_game *game);
void	ft_put_str(t_game *game);

#endif
