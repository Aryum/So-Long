/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:18:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/07 19:23:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	loop_map(t_data *data, void (*f)(t_data *, int, int))
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.size.y)
	{
		x = 0;
		while (x < data->map.size.x)
		{
			f(data, x, y);
			x++;
		}
		y++;
	}
}

void	render_anims(t_data *data)
{
	loop_map(data, render_util_anim);
}

void	render_static(t_data *data)
{
	char	*move;
	char	*count;

	loop_map(data, render_util_background);
	count = lib_itoa(data->map.move_count);
	if (count == NULL)
	{
		lib_error("Failed to alloc move count");
		clean_exit(data);
	}
	move = lib_strjoin("Move count: ", count);
	free(count);
	if (move == NULL)
	{
		lib_error("Failed to alloc move count");
		clean_exit(data);
	}
	mlx_string_put(data->rnd.mlx, data->rnd.window, 50, 50, 0xffffff, move);
	free(move);
}
