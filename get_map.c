/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:04:04 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:04:08 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_extension(char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (1);
	return (0);
}

void	get_nbr_rows(char *map_file, t_game *game)
{
	int		counter;
	int		map_fd;
	char	*temp;

	counter = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		abort_game(game, "Error opening map");
	temp = get_next_line(map_fd);
	while (temp)
	{
		counter++;
		free(temp);
		temp = get_next_line(map_fd);
	}
	if (counter == 0)
		abort_game(game, "Map is empty");
	game->map.rows = counter;
	close(map_fd);
}

void	get_lines(char *map_file, t_game *game)
{
	int		map_fd;
	int		i;
	char	*temp;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		abort_game(game, "Error opening map");
	i = 0;
	while (i < (game->map.rows))
		game->map.map[i++] = get_next_line(map_fd);
	game->map.map[i] = NULL;
	close(map_fd);
	i = -1;
	while (++i < (game->map.rows))
	{
		temp = game->map.map[i];
		game->map.map[i] = ft_strtrim(game->map.map[i], "\n");
		free(temp);
	}
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	get_map(char *map_file, t_game *game)
{
	if (!correct_extension(map_file))
		abort_game(game, "It's not a .ber file");
	get_nbr_rows(map_file, game);
	game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
	if (!game->map.map)
		abort_game(game, "Malloc error");
	get_lines(map_file, game);
}
