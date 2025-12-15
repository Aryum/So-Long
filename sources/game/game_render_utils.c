/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:18:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/07 19:22:19 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	*render_top(t_render r, int x, int max_x)
{
	if (x == 0)
		return (get_frame(r.asset.wall_left, 0));
	else if (x == max_x - 1)
		return (get_frame(r.asset.wall_right, 0));
	else
		return (get_frame(r.asset.wall_top, 0));
}

static void	*render_bottom(t_render r, int x, int max_x)
{
	if (x == 0)
		return (get_frame(r.asset.wall_left, 2));
	else if (x == max_x - 1)
		return (get_frame(r.asset.wall_right, 2));
	else
		return (get_frame(r.asset.wall_bottom, 0));
}

void	render_util_background(t_data *data, int x, int y)
{
	t_render	r;
	void		*img;

	r = data->rnd;
	img = r.asset.ground.sprites[0];
	if (data->map.matrix[y][x] == '1')
	{
		if (y == 0)
			img = render_top(r, x, data->map.size.x);
		else if (y == data->map.size.y - 1)
			img = render_bottom(r, x, data->map.size.x);
		else if (x == 0)
			img = get_frame(r.asset.wall_left, 1);
		else if (x == data->map.size.x - 1)
			img = get_frame(r.asset.wall_right, 1);
		else
			img = get_frame(r.asset.wall_top, 0);
	}
	else if (data->map.matrix[y][x] == 'C')
		img = get_anim(r.asset.collectible, data->rnd.current_frame);
	mlx_put_image_to_window(r.mlx, r.window, img, x * GRID_SZ, y * GRID_SZ);
}

void	render_util_anim(t_data *data, int x, int y)
{
	t_render	r;
	void		*img;
	char		current;

	r = data->rnd;
	img = NULL;
	current = data->map.matrix[y][x];
	if (current == 'P')
		img = get_anim(r.asset.player, data->rnd.current_frame);
	else if (current == 'E')
	{
		if (data->map.col_count == 0)
			img = get_anim(r.asset.exit_open, data->rnd.current_frame);
		else
			img = get_anim(r.asset.exit_closed, data->rnd.current_frame);
	}
	if (img != NULL)
		mlx_put_image_to_window(r.mlx, r.window, img, x * GRID_SZ, y * GRID_SZ);
}
