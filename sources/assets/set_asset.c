/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:44:51 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 10:49:50 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

t_asset	ini_asset(void)
{
	t_asset	ret;

	ini_frames(&ret.wall_top, 0);
	ini_frames(&ret.wall_left, 0);
	ini_frames(&ret.wall_right, 0);
	ini_frames(&ret.wall_bottom, 0);
	ini_frames(&ret.ground, 0);
	ini_frames(&ret.collectible, 0);
	ini_frames(&ret.exit_closed, 0);
	ini_frames(&ret.exit_open, 0);
	ini_frames(&ret.player, 0);
	return (ret);
}

void	clean_asset(t_render *rnd)
{
	clean_frames(rnd->mlx, &rnd->asset.wall_top);
	clean_frames(rnd->mlx, &rnd->asset.wall_left);
	clean_frames(rnd->mlx, &rnd->asset.wall_right);
	clean_frames(rnd->mlx, &rnd->asset.wall_bottom);
	clean_frames(rnd->mlx, &rnd->asset.ground);
	clean_frames(rnd->mlx, &rnd->asset.collectible);
	clean_frames(rnd->mlx, &rnd->asset.exit_closed);
	clean_frames(rnd->mlx, &rnd->asset.exit_open);
	clean_frames(rnd->mlx, &rnd->asset.player);
}

int	set_asset(t_render *rnd)
{
	if (!set_frames(rnd->mlx, &rnd->asset.wall_top, 1, "img/wall/top"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.wall_left, 3, "img/wall/left"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.wall_right, 3, "img/wall/right"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.wall_bottom, 1, "img/wall/bottom"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.ground, 1, "img/ground"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.collectible, 1, "img/col"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.exit_closed, 19, "img/smoke/smoke"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.exit_open, 19, "img/fire/fire"))
		return (0);
	if (!set_frames(rnd->mlx, &rnd->asset.player, 6, "img/player/player"))
		return (0);
	return (1);
}
