/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:06:56 by isibio            #+#    #+#             */
/*   Updated: 2023/04/25 20:07:13 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	parsing_map(char **map)
{
	if (parsing_map_empty(map))
		return (error_message(10, 2), 1);
	if (parsing_map_square(map))
		return (error_message(11, 2), 1);
	if (parsing_map_walls(map))
		return (error_message(12, 2), 1);
	if (parsing_map_composition(map))
		return (error_message(13, 2), 1);
	if (parsing_map_exit_reachable(map))
		return (error_message(14, 2), 1);
	return (0);
}

void	error_message(int error_id, int fd)
{
	if (error_id == 10)
		ft_putstr_fd("[error_message] : Error, map is empty\n", fd);
	if (error_id == 11)
		ft_putstr_fd("[error_message] : Error, map is not a SQUARE\n", fd);
	if (error_id == 12)
		ft_putstr_fd("[error_message] : Error, map border is incorrect\n", fd);
	if (error_id == 13)
		ft_putstr_fd("[error_message] : Error, map composition is incorrect\n", fd);
	if (error_id == 14)
		ft_putstr_fd("[error_message] : Error, position of EXIT or COLLECTIBLE is incorrect\n", fd);
}

int	parsing_map_empty(char **map)
{
	if (!map[0])
		return (1);
	return (0);
}

int	parsing_map_square(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (1);
		i++;
	}	
	return (0);
}

int	parsing_map_walls(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i][0] != WALL && map[i][ft_strlen(map[i]) - 1] != WALL)
			return (1);
		i++;
	}
	if (check_only_char(map[0], WALL))
		return (1);
	if (check_only_char(map[i - 1], WALL))
		return (1);
	return (0);
}

// to do : replace message errors by settings->error_massage
int	parsing_map_composition(char **map)
{
	int	errors;

	errors = 0;
	if (map_count_char(map, EXIT) != 1)
	{
		errors++;
		ft_putstr_fd("[parsing_map_composition] : Error, number of EXIT\n", 2);
	}	
	if (map_count_char(map, PLAYER) != 1)
	{
		errors++;
		ft_putstr_fd("[parsing_map_composition] : Error, number of PLAYER\n", 2);
	}	
	if (map_count_char(map, COLLECTIBLE) == 0)
	{
		errors++;
		ft_putstr_fd("[parsing_map_composition] : Error, number of COLLECTIBLE\n", 2);
	}	
	return (errors);
}

int	parsing_map_exit_reachable(char **map)
{
	int		errors;
	char	**map_virused;
	char	**map_tmp;
	char	virus;

	errors = 0;
	virus = PLAYER;
	map_virused = malloc(sizeof(char *) * (map_len(map) + 1));
	map_clone(map_virused, map);
	while (map_virused != NULL)
	{
		printf("map_virused : %p\n", map_virused);
		printf("map_tmp     : %p\n", map_tmp);

		ft_display_map(map_virused);
		map_virused = map_virus(map_virused, WALL, virus, virus);
		printf("here\n");
		if (map_virused != NULL)
		{
			printf("[parsing_map_exit_reachable] -> clone from:map_virused to:map_tmp\n");
			map_tmp = malloc(sizeof(char *) * (map_len(map) + 1));
			map_clone(map_tmp, map_virused);
		}
	}
	ft_display_map(map_tmp);
	if (map_count_char(map_tmp, EXIT))
	{
		errors++;
		ft_putstr_fd("[parsing_map_exit_reachable] : Error, EXIT not reachable\n", 2);
	}
	if (map_count_char(map_tmp, COLLECTIBLE))
	{
		errors++;
		ft_putstr_fd("[parsing_map_exit_reachable] : Error, not all COLLECTIBLE are reachable\n", 2);
	}
	return (errors);
}

void	map_replace_char(char **map, char to_replace, char replace)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("Check   map[%d][%d] %c | %c \tsame:%d\n", i, j, map[i][j], to_replace, map[i][i] == to_replace);
			if (map[i][i] == to_replace)
				map[i][j] = replace;
			printf("--end\n\n");
			j++;
		}
		i++;
	}
}


// Dessine un char (to_replace) autour et sur un point (défini par x et y) dans une map,
// Ne remplace pas les characteres to_keep
// retourne la map modifiée
char **map_virus_draw_around(char **map, int x, int y, char to_keep, char to_replce)
{
	if (map[y][x] != to_keep)
		map[y][x] = to_replce;
	if (map[y - 1][x] != to_keep)
		map[y - 1][x] = to_replce;
	if (map[y + 1][x] != to_keep)
		map[y + 1][x] = to_replce;
	if (map[y][x - 1] != to_keep)
		map[y][x - 1] = to_replce;
	if (map[y][x + 1] != to_keep)
		map[y][x + 1] = to_replce;
	return (map);
}

// This finction return the number of [to_find] around the char [x ; y]
int	map_search_around(char **map, int x, int y, char to_find)
{
	int	nb_to_find;

	nb_to_find = 0;
	if (map[y - 1][x] == to_find)
		nb_to_find++;
	if (map[y + 1][x] == to_find)
		nb_to_find++;
	if (map[y][x - 1] == to_find)
		nb_to_find++;
	if (map[y][x + 1] == to_find)
		nb_to_find++;
	return (nb_to_find);
}


// Donne la longeur d'une map (verticale)
int	map_len(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

// This function returns the coordinates (x or y, depending on the desired orientation)
// of the char c in the map (after min_len characters searched)
int	get_coordinates(char orientation, char **map, char c, int min_len)
{
	int	i;
	int	j;
	int	searched_char;

	i = 0;
	searched_char = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (searched_char == map_surface(map) - 1)
				return (-1);
			if (map[i][j] == c && searched_char >= min_len)
			{
				if (orientation == 'x')
					return (j);
				if (orientation == 'y')
					return (i);
			}
			searched_char++;
			j++;
		}
		i++;
	}
	return (-1);
}

/*
	* map_virus : return a virused map
	* 
	* 
*/
char	**map_virus(char **map, char to_keep, char to_replace, char virus)
{
	char	**map_virused;
	int		x;
	int		y;
	int		min_len;

	map_virused = malloc(sizeof(char *) * (map_len(map) + 1));
	map_clone(map_virused, map);
	min_len = 0;
	while (1)
	{
		x = get_coordinates('x', map, to_replace, min_len);
		y = get_coordinates('y', map, to_replace, min_len);
		if (min_len == map_surface(map) || x < 0 || y < 0)
			return (free_arr_arr(1, map), NULL);
		map_virused = map_virus_draw_around(map_virused, x, y, WALL, virus);
		if (map_search_around(map, x, y, virus) + map_search_around(map, x, y, to_keep) != 4)
			break ;
		min_len++;
	}
	printf("[map_virus] return a complete map\n");
	return (map_virused);
}

// clone a char ** from src to dest
int	map_clone(char **dest, char **src)
{
	int	i;

	i = 0;
	while (src[i + 0])
	{
		dest[i] = malloc(sizeof(char) * ft_strlen(src[i]) + 1);
		ft_strlcpy(dest[i], src[i], ft_strlen(src[i]) + 1);
		i++;
	}
	dest[i] = NULL;
	return (1);
}

int	map_surface(char **map)
{
	int map_surface;
	int	i;
	int	j;

	i = 0;
	j = 0;
	map_surface = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map_surface++;
			j++;
		}
		i++;
	}
	return (map_surface);
}

int	map_count_char(char **str, char c)
{
	int	nb_occurrence;
	int	i;
	int	j;

	nb_occurrence = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				nb_occurrence++;
			j++;
		}
		i++;
	}
	return (nb_occurrence);
}

void	free_arr_arr(int free_end, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (free_end)
		free(str);
}







