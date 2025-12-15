/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 10:03:07 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/07 19:23:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../data/data.h"

int		key_press(int keycode, t_data *data);

void	move_up(t_data *data, t_mover *m);

void	move_down(t_data *data, t_mover *m);

void	move_left(t_data *data, t_mover *m);

void	move_right(t_data *data, t_mover *m);

int		start_window(t_data *data);

void	render_static(t_data *data);

void	render_util_anim(t_data *data, int x, int y);

void	render_util_background(t_data *data, int x, int y);

void	render_anims(t_data *data);

int		clean_exit(t_data *data);

int		player_move(t_data *data, char c);

#endif