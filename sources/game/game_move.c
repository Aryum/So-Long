/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:05:22 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/07 19:23:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	move(t_data *data, t_mover *m, t_vector vector)
{
	t_vector	new_pos;
	t_map		map;

	map = data->map;
	new_pos = create_vector(m->vct.x + vector.x, m->vct.y + vector.y);
	if (new_pos.y <= 0 || new_pos.x <= 0)
		return ;
	else if (new_pos.y > map.size.y - 1 || new_pos.x > map.size.x - 1)
		return ;
	else if (map.matrix[new_pos.y][new_pos.x] == '1')
		return ;
	else
	{
		if (player_move(data, map.matrix[new_pos.y][new_pos.x]))
		{
			map.matrix[m->vct.y][m->vct.x] = '0';
			map.matrix[new_pos.y][new_pos.x] = m->id;
			m->vct = new_pos;
			render_static(data);
			render_anims(data);
		}
	}
}

void	move_up(t_data *data, t_mover *m)
{
	move(data, m, create_vector(0, -1));
}

void	move_down(t_data *data, t_mover *m)
{
	move(data, m, create_vector(0, 1));
}

void	move_left(t_data *data, t_mover *m)
{
	move(data, m, create_vector(-1, 0));
}

void	move_right(t_data *data, t_mover *m)
{
	move(data, m, create_vector(1, 0));
}
