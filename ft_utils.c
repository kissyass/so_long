/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:15:33 by ykissiko          #+#    #+#             */
/*   Updated: 2023/02/10 15:59:31 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_action_player(t_game *game)
{
	if (game->player_past_x > game->player_x)
		ft_put_img(game, game->player_left, game->player_x, game->player_y);
	else if (game->player_past_x < game->player_x)
		ft_put_img(game, game->player_right, game->player_x, game->player_y);
	else if (game->player_past_y > game->player_y)
		ft_put_img(game, game->player_back, game->player_x, game->player_y);
	else
		ft_put_img(game, game->player_front, game->player_x, game->player_y);
}

void	ft_check_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'V')
	{
		ft_printf("Game over!\n");
		ft_exit(game);
	}
	else if (game->map[y][x] == 'E' && game->coin_num == 0)
	{
		game->moves++;
		ft_printf("%d\n", game->moves);
		ft_exit(game);
	}	
	else if (game->map[y][x] != '1' && game->map[y][x] != 'E')
	{
		game->map[game->player_y][game->player_x] = '0';
		if (game->map[y][x] == 'C')
			game->coin_num--;
		game->moves++;
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		ft_printf("%d\n", game->moves);
	}
}

int	ft_action(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	game->player_past_x = game->player_x;
	game->player_past_y = game->player_y;
	if (key == KEY_ESC)
		ft_exit(game);
	if (key == KEY_A)
		x--;
	else if (key == KEY_W)
		y--;
	else if (key == KEY_D)
		x++;
	else if (key == KEY_S)
		y++;
	else
		return (0);
	ft_check_move(game, x, y);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_set_map(game);
	ft_put_str(game);
	return (0);
}

void	ft_free_game(t_game *game, char **map)
{
	int	i;

	i = -1;
	while (++i < game->map_len)
		free(map[i]);
	free(map);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_image(game->mlx_ptr, game->background);
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_image(game->mlx_ptr, game->player_front);
	mlx_destroy_image(game->mlx_ptr, game->player_back);
	mlx_destroy_image(game->mlx_ptr, game->player_left);
	mlx_destroy_image(game->mlx_ptr, game->player_right);
	mlx_destroy_image(game->mlx_ptr, game->coin);
	mlx_destroy_image(game->mlx_ptr, game->exit_door);
	mlx_destroy_image(game->mlx_ptr, game->enemy);
	ft_free_game(game, game->map);
	exit(0);
	return (0);
}
