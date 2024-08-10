/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:06:22 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:06:39 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_game *game)
{
	if (game->map.facing[0] == 0)
	{
		if (game->map.facing[1] == 1)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.front, 64 * game->map.player_pos.x, 64
				* game->map.player_pos.y);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.back, 64 * game->map.player_pos.x, 64
				* game->map.player_pos.y);
	}
	else
	{
		if (game->map.facing[1] == 1)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.right, 64 * game->map.player_pos.x, 64
				* game->map.player_pos.y);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->tiles.left, 64 * game->map.player_pos.x, 64
				* game->map.player_pos.y);
	}
}

void	deal_new_position(t_game *game)
{
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == COLLECTIBLE)
	{
		game->map.collectibles--;
		game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] = OPEN_SPACE;
	}
	else if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == EXIT && game->map.collectibles == 0)
	{
		ft_printf("You won\n");
		quit_game(game);
	}
}

void	update_previous_position(t_game *game)
{
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.exit,
			TILE_SIZE * game->map.player_pos.x, TILE_SIZE
			* game->map.player_pos.y);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.floor,
			TILE_SIZE * game->map.player_pos.x, TILE_SIZE
			* game->map.player_pos.y);
}

void	facing(t_game *game, int horizontal, int move)
{
	game->map.facing[0] = 0;
	game->map.facing[1] = 0;
	if (horizontal)
	{
		game->map.facing[0] = 1;
		if (move == 1)
			game->map.facing[1] = 1;
		else
			game->map.facing[1] = -1;
	}
	else
	{
		game->map.facing[0] = 0;
		if (move == 1)
			game->map.facing[1] = 1;
		else
			game->map.facing[1] = -1;
	}
}

void	update_position(t_game *game, int horizontal, int move)
{
	facing(game, horizontal, move);
	if (horizontal)
	{
		if (game->map.map[game->map.player_pos.y][game->map.player_pos.x
			+ move] == WALL)
			return ;
		update_previous_position(game);
		game->map.player_pos.x += move;
	}
	else
	{
		if (game->map.map[game->map.player_pos.y
				+ move][game->map.player_pos.x] == WALL)
			return ;
		update_previous_position(game);
		game->map.player_pos.y += move;
	}
	deal_new_position(game);
	render_player(game);
	render_moves(game);
}
