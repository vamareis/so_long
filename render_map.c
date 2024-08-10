/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:06:48 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:06:51 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors_xpm(t_game *game)
{
	if (!game->tiles.wall)
		abort_game(game, "Error in the wall tiles");
	if (!game->tiles.floor)
		abort_game(game, "Error in the floor tiles");
	if (!game->tiles.front)
		abort_game(game, "Error in the player tiles");
	if (!game->tiles.back)
		abort_game(game, "Error in the player tiles");
	if (!game->tiles.right)
		abort_game(game, "Error in the player tiles");
	if (!game->tiles.left)
		abort_game(game, "Error in the player tiles");
	if (!game->tiles.collectibles)
		abort_game(game, "Error in the collectibles tiles");
	if (!game->tiles.exit)
		abort_game(game, "Error in the exit tiles");
}

void	open_xpm(t_game *game)
{
	int	image_size;

	image_size = TILE_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL_TILE,
			&image_size, &image_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_TILE,
			&image_size, &image_size);
	game->tiles.front = mlx_xpm_file_to_image(game->mlx_ptr, FRONT_TILE,
			&image_size, &image_size);
	game->tiles.back = mlx_xpm_file_to_image(game->mlx_ptr, BACK_TILE,
			&image_size, &image_size);
	game->tiles.right = mlx_xpm_file_to_image(game->mlx_ptr, RIGHT_TILE,
			&image_size, &image_size);
	game->tiles.left = mlx_xpm_file_to_image(game->mlx_ptr, LEFT_TILE,
			&image_size, &image_size);
	game->tiles.collectibles = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &image_size, &image_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_TILE,
			&image_size, &image_size);
	check_errors_xpm(game);
}

void	render_tiles(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.wall, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map.map[i][j] == OPEN_SPACE)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.floor, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map.map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.collectibles, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map.map[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.exit, TILE_SIZE * j, TILE_SIZE * i);
		}
	}
	render_player(game);
}

void	render_map(t_game *game)
{
	open_xpm(game);
	render_tiles(game);
}
