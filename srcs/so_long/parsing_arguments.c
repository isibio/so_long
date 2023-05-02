/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argumants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:29:56 by isibio            #+#    #+#             */
/*   Updated: 2023/05/02 13:30:12 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	parsing_arguments(int argc, char **argv)
{
	int	errors;

	(void) argv;
	errors = 0;
	errors += parsing_nb_arguments(argc);
	errors += parsing_map_extension(argv[1]);
	errors += parsing_arguments_map(argv[1]);
	return(errors);
}

int	parsing_arguments_map(char *map_path)
{
	int fd = 0;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (error_message_args(20, 1), 1);
	close(fd);
	return (0);
}

int	parsing_map_extension(char *map_path)
{
	//printf("ft_strnstr(.ber, map_path, ft_strlen(map_path)) = %s\n", ft_strnstr(".ber", map_path, ft_strlen(map_path)));
	if (ft_strnstr(map_path, ".ber", ft_strlen(map_path)) == NULL)
		return (error_message_args(30, 2), 1);
	return (0);
}

int	parsing_nb_arguments(int argc)
{
	if (argc < 2)
		return (error_message_args(10, 1), 1);
	if (argc > 2)
		return (error_message_args(11, 1), 1);
	return (0);
}

void	error_message_args(int error_id, int fd)
{
	char	*fcnm;

	fcnm = "error_message_args";
	if (error_id == 10)
		ft_fprintf(fd, "[%s] : Error, not enough arguments\n", fcnm);
	if (error_id == 11)
		ft_fprintf(fd, "[%s] : Error, too much arguments\n", fcnm);
	if (error_id == 20)
		ft_fprintf(fd, "[%s] : Error, cannot open map\n", fcnm);
	if (error_id == 30)
		ft_fprintf(fd, "[%s] : Error, invalid map extension\n", fcnm);
}
