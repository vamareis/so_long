/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:04:18 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:04:21 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_position(game, 0, -1);
	else if (key == S || key == DOWN)
		update_position(game, 0, 1);
	else if (key == A || key == LEFT)
		update_position(game, 1, -1);
	else if (key == D || key == RIGHT)
		update_position(game, 1, 1);
	return (EXIT_SUCCESS);
}

void	hook_loop(t_game *game)
{
	mlx_hook(game->win_ptr, 2, (1L << 0), on_press, game);
	mlx_hook(game->win_ptr, 17, (1L << 17), quit_game, game);
	mlx_loop(game->mlx_ptr);
}
