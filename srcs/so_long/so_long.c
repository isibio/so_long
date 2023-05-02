/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:30:44 by isibio            #+#    #+#             */
/*   Updated: 2023/04/25 17:30:45 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	nb_char(char *str, char c);

void	ft_display_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int map_fd;
	char **map;
	
	if (parsing_arguments(argc, argv))
		return(ft_putstr_fd("[main] Error arguments\n", 2), 1);
	map_fd = open(argv[1], O_RDONLY);
	map = map_extraction(map_fd); // <---- This line create leaks
	if (parsing_map(map))
		printf("[main] Error\n");
	close(map_fd);
	free_arr_arr(1, map);
	//system("leaks so_long");
	return (0);
}

char	**map_extraction(int map_fd)
{
	int 	i;
	char	*map;
	char	*tmp;
	char	**to_return;

	i = 0;
	map = NULL;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(map_fd);
		if (!tmp)
			break ;
		map = free_and_join(map, tmp);
		free(tmp);
		i++;
	}
	free(tmp);
	to_return = malloc(sizeof(char *) * nb_char(map, '\n') + 2);
	to_return = ft_split(map, '\n');
	to_return[nb_char(map, '\n') + 1] = NULL;
	free(map);
	return (to_return);
}

int	nb_char(char *str, char c)
{
	int	i;
	int	nb_occ;

	i = 0;
	nb_occ = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb_occ++;
		i++;
	}
	return (nb_occ);
}