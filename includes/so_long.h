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
int		parsing_map_walls(char **map);
int		parsing_map_square(char **map);
int		parsing_map_composition(char **map);
int		parsing_map_exit_reachable(char **map);

char	**map_virus(char **map, char to_keep, char to_replace);


/* ===| Utils |=== */
int		count_char(char **str, char c);
int		check_only_char(char *str, char c);
#endif
