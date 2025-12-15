/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:09:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/24 13:13:26 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_rows(t_map map)
{
	int	i;

	i = 0;
	while (map.matrix[0][i] != '\0')
	{
		if (map.matrix[0][i] != '1')
			return (lib_error("Top row isn't wall"), 0);
		i++;
	}
	i = 0;
	while (map.matrix[map.size.y - 1][i] != '\0')
	{
		if (map.matrix[map.size.y - 1][i] != '1')
			return (lib_error("Bottom row isn't wall"), 0);
		i++;
	}
	return (1);
}

static int	check_collums(t_map map)
{
	int	i;

	i = 1;
	while (i < map.size.y - 1)
	{
		if (map.matrix[i][0] != '1' || map.matrix[i][map.size.x - 1] != '1')
			return (lib_error("Sides arent wall"), 0);
		i++;
	}
	return (1);
}

int	check_form(t_map *map)
{
	int	x;
	int	y;

	x = lib_strlen(map->matrix[0]);
	y = 0;
	if (x < 5)
		return (lib_error("Map lenght too short"), 0);
	while (map->matrix[y] != NULL)
	{
		if ((int)lib_strlen(map->matrix[y]) != x)
			return (lib_error("Inconsistent x size"), 0);
		y++;
	}
	if (y < 3)
		return (lib_error("Map height too short"), 0);
	map->size = create_vector(x, y);
	if (!check_collums(*map) || !check_rows(*map))
		return (0);
	return (1);
}
