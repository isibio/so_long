/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_operators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:41:16 by isibio            #+#    #+#             */
/*   Updated: 2023/05/30 12:00:57 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

// This function returns the coordinates
// 	(x/y, depending on the desired orientation)
// of the char c in the map (after min_len characters searched)
int	get_coordinates(char orientation, char **map, char c, int min_len)
{
	int	i;
	int	j;
	int	searched_char;

	i = -1;
	searched_char = 0;
	while (map[++i])
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
	}
	return (-1);
}

int	map_surface(char **map)
{
	int	map_surface;
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
