/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 10:04:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/10/15 12:38:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//usleep(40000);
static int	loop_logic(t_data *data)
{
	render_anims(data);
	data->rnd.current_frame++;
	usleep(40000);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == key_w)
		move_up(data, &(data->map.player));
	else if (keycode == key_s)
		move_down(data, &(data->map.player));
	else if (keycode == key_a)
		move_left(data, &(data->map.player));
	else if (keycode == key_d)
		move_right(data, &(data->map.player));
	else if (keycode == key_esc)
		clean_exit(data);
	return (0);
}

int	clean_exit(t_data *data)
{
	t_render	rnd;

	rnd = data->rnd;
	clean_asset(&rnd);
	if (rnd.window != NULL)
		mlx_destroy_window(rnd.mlx, rnd.window);
	if (rnd.mlx != NULL)
		mlx_destroy_display(rnd.mlx);
	free(rnd.mlx);
	clear_data(*data);
	exit(0);
}

int	start_window(t_data *data)
{
	t_vector	sz;

	sz = data->map.size;
	sz.x *= GRID_SZ;
	sz.y *= GRID_SZ;
	data->rnd.mlx = mlx_init();
	if (data->rnd.mlx == NULL)
		return (lib_error("Failed to ini window"), clean_exit(data), 0);
	if (!set_asset(&(data->rnd)))
		return (lib_error("Failed to get xpm"), clean_exit(data), 0);
	data->rnd.window = mlx_new_window(data->rnd.mlx, sz.x, sz.y, "Long Souls");
	if (data->rnd.window == NULL)
		return (lib_error("Failed to create window"), clean_exit(data), 0);
	mlx_hook(data->rnd.window, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->rnd.window, DestroyNotify, NoEventMask, clean_exit, data);
	mlx_loop_hook(data->rnd.mlx, loop_logic, data);
	render_static(data);
	mlx_loop(data->rnd.mlx);
	return (0);
}
