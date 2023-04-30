/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:13:50 by ykissiko          #+#    #+#             */
/*   Updated: 2023/02/09 20:22:55 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_init_param(game);
	if (ft_read_map(game, map) != 1)
	{
		free(game);
		return ;
	}
	if (ft_check_map(game) != 1)
	{
		ft_free_game(game, game->map);
		ft_free_game(game, game->map_check);
		free(game);
		return ;
	}
	ft_free_game(game, game->map_check);
	ft_init_map_2(game);
}

void	ft_init_map_2(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window
		(game->mlx_ptr, 64 * game->map_width, 64 * game->map_len, "SO_LONG");
	if (!game->mlx_ptr || !game->win_ptr
		|| ft_set_image_1(game) != 1 || ft_set_image_2(game) != 1)
		ft_printf("MLX failed\n");
	ft_set_map(game);
	ft_put_str(game);
	mlx_hook(game->win_ptr, 17, 1L << 2, ft_exit, game);
	mlx_hook(game->win_ptr, 2, 1L << 3, ft_action, game);
	mlx_loop(game->mlx_ptr);
	free(game);
}

int	main(int argc, char **argv)
{
	if (ft_check_input(argc, argv) != 1)
		return (0);
	ft_init_map(argv[1]);
	return (0);
}
