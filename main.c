/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:05:39 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 17:05:42 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	args_check(int argc, char **argv)
{
	if (argc != 2)
		abort_game(NULL, "Invalid number of arguments");
	if (argv[1] == NULL)
		abort_game(NULL, "Argument is NULL");
}

int	main(int argc, char **argv)
{
	t_game	game;

	args_check(argc, argv);
	game = init_game();
	get_map(argv[1], &game);
	map_error_analysis(&game);
	initialize(&game);
	render_map(&game);
	hook_loop(&game);
	return (EXIT_SUCCESS);
}

void	print_map(t_game *game)
{
	int	i;

	ft_printf("number of rows: %d\n", game->map.rows);
	ft_printf("number of columns: %d\n", game->map.columns);
	i = -1;
	while (++i < game->map.rows)
	{
		ft_printf("%s", game->map.map[i]);
		ft_printf("\n");
	}
}
