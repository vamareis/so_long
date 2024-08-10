/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:07:16 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:07:19 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_tiles(t_game *game)
{
	if (game->tiles.collectibles)
		mlx_destroy_image(game->mlx_ptr, game->tiles.collectibles);
	if (game->tiles.exit)
		mlx_destroy_image(game->mlx_ptr, game->tiles.exit);
	if (game->tiles.floor)
		mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
	if (game->tiles.front)
		mlx_destroy_image(game->mlx_ptr, game->tiles.front);
	if (game->tiles.back)
		mlx_destroy_image(game->mlx_ptr, game->tiles.back);
	if (game->tiles.right)
		mlx_destroy_image(game->mlx_ptr, game->tiles.right);
	if (game->tiles.left)
		mlx_destroy_image(game->mlx_ptr, game->tiles.left);
	if (game->tiles.wall)
		mlx_destroy_image(game->mlx_ptr, game->tiles.wall);
}

void	destroy(t_game *game)
{
	if (!game)
		return ;
	destroy_tiles(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.map)
		free_tab(game->map.map);
}

void	abort_game(t_game *game, char *message)
{
	destroy(game);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	render_moves(t_game *game)
{
	char	*moves;

	game->moves++;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.wall, 0,
		0);
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 29, 33, 0, moves);
	free(moves);
}
