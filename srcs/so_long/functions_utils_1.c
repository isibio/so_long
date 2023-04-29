/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:51:41 by isibio            #+#    #+#             */
/*   Updated: 2023/04/25 19:51:45 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*free_and_join(char *s1, char *c)
{
	char	*tmp;
	char	*s2;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	s2 = malloc(sizeof(char) * 2);
	ft_strlcpy(s2, c, ft_strlen(c) + 1);
	tmp = ft_strjoin(s1, s2);
	return (free(s1), free(s2), tmp);
}

int	check_only_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}
