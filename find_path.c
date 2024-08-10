/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:03:36 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:03:53 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**test_grid(t_game *game)
{
	char	**test;
	int		i;

	test = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!test)
		abort_game(game, "Malloc error creating test grid");
	i = 0;
	while (i < game->map.rows)
	{
		test[i] = ft_strdup(game->map.map[i]);
		if (!test[i])
		{
			free_tab(test);
			abort_game(game, "Error in malloc of map line");
		}
		i++;
	}
	return (test);
}

int	flood(char **tab, t_game *game, t_point cur)
{
	static int	collectibles = 0;
	static int	exit = 0;

	if (tab[cur.y][cur.x] == WALL)
		return (0);
	else if (tab[cur.y][cur.x] == COLLECTIBLE)
		collectibles++;
	else if (tab[cur.y][cur.x] == EXIT)
		exit++;
	tab[cur.y][cur.x] = WALL;
	flood(tab, game, (t_point){cur.x + 1, cur.y});
	flood(tab, game, (t_point){cur.x - 1, cur.y});
	flood(tab, game, (t_point){cur.x, cur.y + 1});
	flood(tab, game, (t_point){cur.x, cur.y - 1});
	if (game->map.collectibles == collectibles && exit == 1)
		return (1);
	else
		return (0);
}

void	find_path(t_game *game)
{
	char	**grid;

	grid = test_grid(game);
	if (!grid)
		abort_game(game, "Malloc error creating test grid");
	if (!flood(grid, game, game->map.player_pos))
	{
		free_tab(grid);
		abort_game(game, "There are unreachable elements in the map");
	}
	free_tab(grid);
}
