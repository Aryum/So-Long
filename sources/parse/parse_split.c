/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 10:40:32 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 10:52:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	newline_checker(char *file)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (file[i] != '\0')
	{
		if (flag == 0 && file[i] != '\n')
			flag = 1;
		else if (flag == 1 && file[i] == '\n' && file[i + 1] == '\n')
			flag = 2;
		else if (flag == 2 && file[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_split(t_map *map_info, char *file)
{
	size_t	size;

	size = lib_strlen(file);
	if (size > 2147483647)
		return (free(file), lib_error("File too big"), 0);
	if (!newline_checker(file))
		return (free(file), lib_error("Invalid map"), 0);
	map_info->matrix = lib_split(file, '\n');
	free(file);
	if (map_info->matrix == NULL)
		return (lib_error("Failed map split"), 0);
	return (1);
}
