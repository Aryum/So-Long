/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:59:35 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 11:41:59 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define GRID_SZ 96

# include "../../mlx/mlx.h"
# include "../../mlx/mlx_int.h"
# include "../../helpers/lib/lib.h"
# include "../../helpers/printf/print.h"

typedef struct s_frames
{
	void	**sprites;
	int		count;
}	t_frames;

typedef struct s_asset
{
	t_frames	wall_right;
	t_frames	wall_left;
	t_frames	wall_top;
	t_frames	wall_bottom;
	t_frames	ground;
	t_frames	player;
	t_frames	collectible;
	t_frames	exit_closed;
	t_frames	exit_open;
}	t_asset;

typedef struct s_render
{
	t_asset	asset;
	void	*window;
	void	*mlx;
	size_t	current_frame;
}	t_render;

t_asset	ini_asset(void);
int		set_asset(t_render *rnd);
void	clean_asset(t_render *rnd);

int		ini_frames(t_frames *frames, int count);
int		set_frames(void *mlx, t_frames *frames, int count, char *path);
void	clean_frames(void *mlx, t_frames *frames);
void	*get_frame(t_frames frame, int index);

void	*get_anim(t_frames frame, int currentFrame);

#endif