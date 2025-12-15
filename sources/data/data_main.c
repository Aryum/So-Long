/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 10:13:26 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 11:39:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_data	ini_data(t_map map)
{
	t_data		ret;
	t_render	rnd;

	rnd.mlx = NULL;
	rnd.window = NULL;
	rnd.current_frame = 0;
	rnd.asset = ini_asset();
	ret.map = map;
	ret.rnd = rnd;
	return (ret);
}

void	clear_data(t_data data)
{
	clear_map(data.map);
}
