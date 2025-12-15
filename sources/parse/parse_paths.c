/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:52:26 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 10:53:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	dup_map(t_map map, char ***map_dup)
{
	int	i;

	*map_dup = lib_calloc(map.size.y + 1, sizeof(char *));
	if (*map_dup == NULL)
		return (failed_dup(), 0);
	i = 0;
	while (i < map.size.y)
	{
		(*map_dup)[i] = lib_strdup(map.matrix[i]);
		if ((*map_dup)[i] == NULL)
			return (failed_dup(), lib_split_clean(*map_dup), 0);
		i++;
	}
	return (1);
}

static void	flood_fill(char **matrix, t_vector v)
{
	char	current;

	current = matrix[v.y][v.x];
	if (current == '1' || current == 'F')
		return ;
	matrix[v.y][v.x] = 'F';
	if (current == 'E')
		return ;
	flood_fill(matrix, create_vector(v.x + 1, v.y));
	flood_fill(matrix, create_vector(v.x, v.y + 1));
	flood_fill(matrix, create_vector(v.x - 1, v.y));
	flood_fill(matrix, create_vector(v.x, v.y - 1));
}

static int	has_path(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_paths(t_map map)
{
	char	**map_dup;

	if (!dup_map(map, &map_dup))
		return (0);
	flood_fill(map_dup, map.player.vct);
	if (!has_path(map_dup))
		return (lib_split_clean(map_dup), lib_error("Has invalid paths"), 0);
	lib_split_clean(map_dup);
	return (1);
}
