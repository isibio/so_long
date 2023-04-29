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

#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "../lib/libft/includes/libft.h"

//typedef struct s_settings
//{
//	char	wall;
//	char	player;
//	char	wall;
//
//}t_settings;

char	**map_extraction(int map_fd);
char	*free_and_join(char *s1, char *s2);

/* ===| Parsing |=== */
int		parsing_map(char **map);
int		parsing_map_empty(char **map);
int		parsing_map_walls(char **map);
int		parsing_map_square(char **map);
int		parsing_map_composition(char **map);
int		parsing_map_exit_reachable(char **map);

int		map_len(char **map);
int		map_surface(char **map);
int		map_clone(char **dest, char **src);
int		map_count_char(char **str, char c);
int		map_search_around(char **map,int x, int y, char to_find);
void	map_replace_char(char **map, char to_replace, char replace);
int		get_coordinates(char orientation, char **map, char c, int min_len);
char	**map_virus(char **map, char to_keep, char to_replace, char virus);
char 	**map_virus_draw_around(char **map, int x, int y, char to_keep, char virus);

/* ===| Utils |=== */
void	ft_display_map(char **map);
int		check_only_char(char *str, char c);
void	error_message(int error_id, int fd);
void	free_arr_arr(int free_end, char **str);
#endif
