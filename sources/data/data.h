/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:27:16 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/05 16:41:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <stddef.h>
# include "../../helpers/printf/print.h"
# include "../assets/assets.h"

typedef enum e_keys
{
	key_w = 119,
	key_a = 97,
	key_s = 115,
	key_d = 100,
	key_esc = 65307
}	t_keys;

typedef struct s_vector
{
	int	x;
	int	y;
	int	is_set;
}	t_vector;

typedef struct s_mover
{
	char		id;
	t_vector	vct;
	t_vector	dir;
}	t_mover;

typedef struct s_map
{
	t_mover		player;
	t_vector	size;
	t_vector	door_pos;
	t_vector	*collectibles_pos;
	char		**matrix;
	int			col_count;
	int			move_count;
}	t_map;

typedef struct s_data
{
	t_map		map;
	t_render	rnd;
}	t_data;

t_vector	ini_vector(void);

t_data		ini_data(t_map map);

t_map		ini_map(void);

t_render	ini_render(void);

t_mover		create_mover(char c);

t_vector	create_vector(int x, int y);

void		clear_data(t_data data);

void		clear_map(t_map map);

#endif