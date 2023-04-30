/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:15:49 by ykissiko          #+#    #+#             */
/*   Updated: 2023/02/10 12:38:44 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_map_check(t_game *game, char *map)
{
	int		fd;
	char	c;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Map doesn't exist\n"));
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			game->map_len++;
	}
	close(fd);
	game->map_len++;
	game->map = malloc(sizeof(char *) * game->map_len + 1);
	game->map_check = malloc(sizeof(char *) * game->map_len + 1);
	return (1);
}

int	ft_check_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_width)
	{
		if (game->map_check[0][i] != '1'
			|| game->map_check[game->map_len - 1][i] != '1')
			return (ft_printf("Map is not surrounded by walls\n"));
	}
	i = -1;
	while (++i < game->map_len)
	{
		if (game->map_check[i][0] != '1'
			|| game->map_check[i][game->map_width - 1] != '1')
			return (ft_printf("Map is not surrounded by walls\n"));
	}
	if (ft_check_map_obj(game) != 1)
		return (2);
	if (ft_check_rect(game) != 1)
		return (2);
	ft_check_path(game, game->player_x, game->player_y);
	if (game->coin_num_check != 0 || game->exit_num_check == 0)
		return (ft_printf("It is impossible to clear the game\n"));
	return (1);
}

int	ft_check_rect(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (++i < game->map_len)
	{
		len = 0;
		while (game->map_check[i][len] != '\0'
			&& game->map_check[i][len] != '\n')
			len++;
		if (len != game->map_width)
			return (ft_printf("Map is not rectungular\n"));
	}
	return (1);
}

void	ft_set_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_len)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == '1')
				ft_put_img(game, game->wall, x, y);
			else if (game->map[y][x] == '0')
				ft_put_img(game, game->background, x, y);
			else if (game->map[y][x] == 'C')
				ft_put_img(game, game->coin, x, y);
			else if (game->map[y][x] == 'E')
				ft_put_img(game, game->exit_door, x, y);
			else if (game->map[y][x] == 'V')
				ft_put_img(game, game->enemy, x, y);
			if (game->map[y][x] == 'P' && game->moves == 0)
				ft_put_img(game, game->player_front, x, y);
			else if (game->map[y][x] == 'P' && game->moves > 0)
				ft_action_player(game);
		}
	}
}

void	ft_put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x * 64, y * 64);
}
