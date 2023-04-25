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

int main(int argc, char **argv)
{
	int map_fd;
	char **map;
	(void) argc;

	map_fd = open(argv[1], O_RDONLY);
	map = map_extraction(map_fd);

	if (parsing_map(map))
		printf("ERROR\n");

	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	close(map_fd);
	//system("leaks so_long");
	return (0);
}

char	**map_extraction(int map_fd)
{
	int 	i;
	char	*map;
	char	*tmp;

	i = 0;
	map = ft_strdup("");
	tmp = NULL;
	while (1)
	{
		//printf("%p\n", tmp);
		tmp = get_next_line(map_fd);
		if (!tmp)
			break ;
		map = free_and_join(map, tmp);
		free(tmp);
		i++;
	}
	free(tmp);
	free(map);
	return (ft_split(map, '\n'));
}