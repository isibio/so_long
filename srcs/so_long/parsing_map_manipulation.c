/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_manipulation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:42:15 by isibio            #+#    #+#             */
/*   Updated: 2023/05/03 11:42:16 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**map_virus(char **map, char to_keep, char to_replace, char virus)
{
	char	**map_virused;
	int		x;
	int		y;
	int		min_len;
	char	c[2];

	map_virused = malloc(sizeof(char *) * (map_len(map) + 1));
	map_clone(map_virused, map);
	min_len = 0;
	while (1)
	{
		x = get_coordinates('x', map, to_replace, min_len);
		y = get_coordinates('y', map, to_replace, min_len);
		if (min_len == map_surface(map) || x < 0 || y < 0)
			return (free_arr_arr(1, map), free_arr_arr(1, map_virused), NULL);
		c[0] = WALL;
		c[1] = virus;
		map_virused = map_virus_draw_around(map_virused, x, y, c);
		if (map_search_around(map, x, y, virus)
			+ map_search_around(map, x, y, to_keep) != 4)
			break ;
		min_len++;
	}
	return (free_arr_arr(1, map), map_virused);
}

void	map_replace_char(char **map, char to_replace, char replace)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][i] == to_replace)
				map[i][j] = replace;
			j++;
		}
		i++;
	}
}

// to[0] = to_keep
// to[1] = to_replace
char	**map_virus_draw_around(char **map, int x, int y, char *to)
{
	if (map[y][x] != to[0])
		map[y][x] = to[1];
	if (map[y - 1][x] != to[0])
		map[y - 1][x] = to[1];
	if (map[y + 1][x] != to[0])
		map[y + 1][x] = to[1];
	if (map[y][x - 1] != to[0])
		map[y][x - 1] = to[1];
	if (map[y][x + 1] != to[0])
		map[y][x + 1] = to[1];
	return (map);
}

int	map_clone(char **dest, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = malloc(sizeof(char) * ft_strlen(src[i]) + 1);
		ft_strlcpy(dest[i], src[i], ft_strlen(src[i]) + 1);
		i++;
	}
	dest[i] = NULL;
	return (1);
}
