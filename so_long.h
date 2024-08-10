/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:07:00 by vamachad          #+#    #+#             */
/*   Updated: 2024/08/06 18:11:32 by vamachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "keys.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "tiles.h"

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

typedef struct s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct s_map
{
	char				**map;
	int					rows;
	int					columns;
	int					collectibles;
	int					exit;
	int					player;
	int					facing[2];
	t_point				player_pos;
}						t_map;

typedef struct s_tiles
{
	void				*wall;
	void				*floor;
	void				*front;
	void				*back;
	void				*right;
	void				*left;
	void				*collectibles;
	void				*exit;
}						t_tiles;

typedef struct s_game
{
	t_map				map;
	void				*mlx_ptr;
	void				*win_ptr;
	t_tiles				tiles;
	int					moves;
}						t_game;

static inline t_game	init_game(void)
{
	return ((t_game){.map.map = NULL, .map.rows = 0, .map.columns = 0,
		.map.collectibles = 0, .map.exit = 0, .map.player = 0,
		.map.facing[0] = 0, .map.facing[1] = 1, .tiles.wall = NULL,
		.tiles.floor = NULL, .tiles.front = NULL, .tiles.back = NULL,
		.tiles.right = NULL, .tiles.left = NULL, .tiles.collectibles = NULL,
		.tiles.exit = NULL, .moves = 0});
}

void					args_check(int argc, char **argv);
void					abort_game(t_game *game, char *message);
void					destroy(t_game *game);
void					destroy_tiles(t_game *game);
void					get_map(char *map_file, t_game *game);
int						correct_extension(char *map_file);
void					get_nbr_rows(char *map_file, t_game *game);
void					get_lines(char *map_file, t_game *game);
void					map_error_analysis(t_game *game);
int						check_elements(t_game *game);
int						check_elements_aid(char element, t_game *game);
int						is_closed(t_game *game);
int						is_rectangular(t_game *game);
void					find_path(t_game *game);
char					**test_grid(t_game *game);
int						flood(char **tab, t_game *game, t_point cur);
void					free_tab(char **tab);
void					initialize(t_game *game);
void					render_map(t_game *game);
void					open_xpm(t_game *game);
void					check_errors_xpm(t_game *game);
void					render_tiles(t_game *game);
void					render_player(t_game *game);
void					hook_loop(t_game *game);
int						on_press(int key, t_game *game);
void					update_position(t_game *game, int horizontal, int move);
void					update_previous_position(t_game *game);
void					deal_new_position(t_game *game);
int						quit_game(t_game *game);
void					render_moves(t_game *game);
void					print_map(t_game *game);

#endif
