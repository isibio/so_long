/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:29:27 by isibio            #+#    #+#             */
/*   Updated: 2023/04/25 17:30:02 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL			'1'
# define GROUND			'0'
# define PLAYER			'P'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define TEXTURE_RESOLUTION	64
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include "../lib/libft/includes/libft.h"

typedef struct s_textures
{
	char	*wall;
	char	*player;
	char	*coll;
	char	*ground;
	char	*exit;

	void	*wall_xpm;
	void	*player_xpm;
	void	*coll_xpm;
	void	*ground_xpm;
	void	*exit_xpm;
}t_textures;

typedef struct s_player
{
	int		movements;
}t_player;

typedef struct s_data
{
	t_textures	texture;
	t_player	player;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
}t_data;

char		**map_extraction(int map_fd);
char		*free_and_join(char *s1, char *s2);
/* ===| Parsing |=== */
int			parsing_map(char **map);
int			parsing_map_empty(char **map);
int			parsing_map_walls(char **map);
int			parsing_map_square(char **map);
int			parsing_map_composition(char **map);
int			parsing_map_exit_reachable(char **map);
int			error_message_map(int error_id, char *prefix, int fd, int ret);
void		map_replace_char(char **map, char to_replace, char replace);
int			map_len(char **map);
int			map_surface(char **map);
int			map_clone(char **dest, char **src);
int			map_count_char(char **str, char c);
int			map_search_around(char **map, int x, int y, char to_find);
int			get_coordinates(char orientation, char **map, char c, int min_len);
char		**map_virus(char **map, char to_keep, char to_replace,
				char virus);
char		**map_virus_draw_around(char **map, int x, int y, char *to);
int			parsing_nb_arguments(int argc);
int			parsing_map_extension(char *map_path);
int			parsing_map_err(int error_id, char *prefix, int fd, int ret);
int			parsing_arguments_map(char *map_path);
int			parsing_arguments(int argc, char **argv);
void		error_message_args(int error_id, int fd);
/* ===| Game |=== */
int			game_main(char **map);
t_data		game_init(void *mlx_ptr, char **map);
t_data		data_init(void *mlx_ptr, char **map);
void		game_loop(t_data data);
void		game_exit(t_data *data, int exit_x, int exit_y);
int			game_end(void);
/* ===| Control |=== */
int			control_key_management(int key, t_data *data);
t_data		*control_key_move(int key, t_data *data);
t_data		*move_object(t_data *data, char character,
				char *direction, char collision);
/* ===| Graphic |=== */
void		*graphic_new_window(void *mlx_ptr, char **map);
void		graphic_put_textures(t_textures t, char **map, void *m, void *w);
t_textures	graphic_init_textures(void *mlx_ptr);
/* ===| Utils |=== */
void		ft_display_map(char **map);
int			check_only_char(char *str, char c);
void		free_arr_arr(int free_end, char **str);
#endif