/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:14:09 by ykissiko          #+#    #+#             */
/*   Updated: 2023/02/10 16:00:32 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_map(t_game *game, char *map)
{
	int	fd;
	int	i;

	if (ft_read_map_check(game, map) != 1)
		return (2);
	fd = open(map, O_RDONLY);
	i = -1;
	while (++i < game->map_len)
	{
		game->map[i] = get_next_line(fd);
		game->map_check[i] = ft_strdup(game->map[i]);
	}
	i = -1;
	while (game->map[0][++i] != '\n')
		game->map_width++;
	game->map[game->map_len] = NULL;
	game->map_check[game->map_len] = NULL;
	close(fd);
	return (1);
}

int	ft_set_image_1(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player_front = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/character_front.xpm", &img_width, &img_height);
	game->player_back = mlx_xpm_file_to_image
		(game->mlx_ptr, "textures/character_back.xpm", &img_width, &img_height);
	game->player_left = mlx_xpm_file_to_image
		(game->mlx_ptr, "textures/character_left.xpm", &img_width, &img_height);
	game->player_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/character_right.xpm", &img_width, &img_height);
	if (!game->player_front || !game->player_back
		|| !game->player_left || !game->player_right)
		return (ft_printf("Player .xpm file failed\n"));
	return (1);
}

int	ft_set_image_2(t_game *game)
{
	int	img_width;
	int	img_height;

	game->background = mlx_xpm_file_to_image
		(game->mlx_ptr, "textures/background.xpm", &img_width, &img_height);
	game->coin = mlx_xpm_file_to_image
		(game->mlx_ptr, "textures/coin.xpm", &img_width, &img_height);
	game->exit_door = mlx_xpm_file_to_image
		(game->mlx_ptr, "textures/exit.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image
		(game->mlx_ptr, "textures/wall.xpm", &img_width, &img_height);
	game->enemy = mlx_xpm_file_to_image
		(game->mlx_ptr, "textures/enemy.xpm", &img_width, &img_height);
	if (!game->background || !game->coin
		|| !game->exit_door || !game->wall || !game->enemy)
		return (ft_printf("Background .xpm file failed\n"));
	return (1);
}

void	ft_init_param(t_game *game)
{
	game->exit_num = 0;
	game->exit_num_check = 0;
	game->player_num = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->coin_num = 0;
	game->coin_num_check = 0;
	game->moves = 0;
	game->map_len = 0;
	game->map_width = 0;
	game->player_past_x = 0;
	game->player_past_y = 0;
	game->map = NULL;
	game->map_check = NULL;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

void	ft_put_str(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		10, 10, 16777215, str);
	free(str);
}
