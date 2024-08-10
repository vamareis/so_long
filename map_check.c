/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:05:53 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:05:56 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows - 1)
	{
		if (ft_strlen(game->map.map[i]) != game->map.columns)
			return (0);
		i++;
	}
	return (1);
}

int	is_closed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.map[0][i] != WALL || game->map.map[game->map.rows
			- 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != WALL || game->map.map[i][game->map.columns
			- 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == PLAYER)
			{
				game->map.player++;
				game->map.player_pos = (t_point){j, i};
			}
			else
			{
				if (!check_elements_aid(game->map.map[i][j], game))
					return (0);
			}
		}
	}
	return (1);
}

int	check_elements_aid(char element, t_game *game)
{
	if (element == COLLECTIBLE)
	{
		game->map.collectibles++;
		return (1);
	}
	else if (element == EXIT)
	{
		game->map.exit++;
		return (1);
	}
	else if (element == WALL || element == OPEN_SPACE
		|| element == '\0')
		return (1);
	return (0);
}

void	map_error_analysis(t_game *game)
{
	if (!check_elements(game))
		abort_game(game, "Unknown element in the map");
	if (!is_rectangular(game))
		abort_game(game, "The map is not rectangular");
	if (!is_closed(game))
		abort_game(game, "The map is not surrounded by walls");
	if (game->map.player < 1)
		abort_game(game, "There is no player start position in the map");
	if (game->map.player > 1)
		abort_game(game, "There is more than one player in the map");
	if (game->map.exit != 1)
		abort_game(game, "There is no exit in the map");
	if (game->map.collectibles == 0)
		abort_game(game, "There are no collectibles in the map");
	find_path(game);
}
