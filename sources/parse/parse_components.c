/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:59:52 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 10:53:27 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	set_pos(t_vector *vector, size_t x, size_t y, char *msg)
{
	if (vector->is_set)
		return (lib_error(msg), 0);
	*vector = create_vector(x, y);
	return (1);
}

static int	is_valid(t_map *map, size_t x, size_t y)
{
	char	c;

	c = map->matrix[y][x];
	if (c == 'C')
	{
		map->col_count++;
		return (1);
	}
	else if (c == 'E')
		return (set_pos(&map->door_pos, x, y, "More than one exit"));
	else if (c == 'P')
		return (set_pos(&map->player.vct, x, y, "More than one player"));
	else if (c != '1' && c != '0')
		return (lib_error("Invalid char"), 0);
	return (1);
}

static void	send_msg(int val, int *sucess, char *msg)
{
	if (!val)
	{
		lib_error(msg);
		*sucess = 0;
	}
}

int	check_components(t_map *map)
{
	int	x;
	int	y;
	int	sucess;

	y = 1;
	while (map->matrix[y] != NULL)
	{
		x = 1;
		while (map->matrix[y][x] != '\0')
		{
			if (!is_valid(map, x, y))
				return (0);
			x++;
		}
		y++;
	}
	sucess = 1;
	send_msg(map->player.vct.is_set, &sucess, "Player not set");
	send_msg(map->door_pos.is_set, &sucess, "Door not set");
	send_msg(map->col_count > 0, &sucess, "No Collectibles");
	return (sucess);
}
