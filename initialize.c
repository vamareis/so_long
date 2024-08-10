/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:04:30 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:04:33 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		abort_game(game, "mlx pointer not obtained");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * TILE_SIZE,
			game->map.rows * TILE_SIZE, "so long");
	if (!game->win_ptr)
		abort_game(game, "window pointer not obtained");
}
