/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:03:17 by ykissiko          #+#    #+#             */
/*   Updated: 2023/02/15 17:10:31 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ext(char *file, int len, char *ext)
{
	int	flen;
	int	i;

	flen = ft_strlen(file);
	i = 0;
	while (i < len)
	{
		if (file[flen - len + i] != ext[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_input(int argc, char **argv)
{
	if (argc < 2)
		return (ft_printf("Enter at least 1 argument\n"));
	else if (argc > 2)
		ft_printf("Only first file will be processed\n");
	if (ft_check_ext(argv[1], 4, ".ber") != 1)
		return (ft_printf("map should be .ber file\n"));
	return (1);
}

void	ft_check_path(t_game *game, int x, int y)
{
	if (game->map_check[y][x] == 'E')
		game->exit_num_check++;
	if (game->map_check[y][x] != 'E' && game->map_check[y][x]
		!= '1' && game->map_check[y][x] != 'V')
	{
		if (game->map_check[y][x] == 'C')
			game->coin_num_check--;
		game->map_check[y][x] = 'x';
		if (game->map_check[y + 1][x] != '1' && game->map_check[y + 1][x]
			!= 'x' && game->map_check[y][x + 1] != 'V')
			ft_check_path(game, x, y + 1);
		if (game->map_check[y - 1][x] != '1' && game->map_check[y - 1][x]
			!= 'x' && game->map_check[y][x + 1] != 'V')
			ft_check_path(game, x, y - 1);
		if (game->map_check[y][x + 1] != '1' && game->map_check[y][x + 1]
			!= 'x' && game->map_check[y][x + 1] != 'V')
			ft_check_path(game, x + 1, y);
		if (game->map_check[y][x - 1] != '1' && game->map_check[y][x - 1]
			!= 'x' && game->map_check[y][x + 1] != 'V')
			ft_check_path(game, x - 1, y);
	}
}

int	ft_check_map_obj(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < game->map_len)
	{
		i = -1;
		while (++i < game->map_width)
		{
			if (game->map_check[j][i] == 'E')
				game->exit_num++;
			else if (game->map_check[j][i] == 'P')
			{
				game->player_num++;
				game->player_x = i;
				game->player_y = j;
			}
			else if (game->map_check[j][i] == 'C')
				game->coin_num++;
			else if (game->map_check[j][i] != '1' && game->map_check[j][i]
				!= '0' && game->map_check[j][i] != 'V')
				return (ft_printf("You have unidentified object!\n"));
		}
	}
	return (ft_check_map_obj_2(game));
}

int	ft_check_map_obj_2(t_game *game)
{
	if (game->exit_num > 1 || game->player_num > 1)
		return (ft_printf("Only 1 player and 1 exit are allowed\n"));
	if (game->exit_num == 0 || game->player_num == 0 || game->coin_num == 0)
		return (ft_printf("Add at least 1 palyer, 1 exit, and 1 coin\n"));
	game->coin_num_check = game->coin_num;
	return (1);
}
