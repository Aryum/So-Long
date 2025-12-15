/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:49:14 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/05 16:41:26 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_map	ini_map(void)
{
	t_map	ret;

	ret.matrix = NULL;
	ret.collectibles_pos = NULL;
	ret.col_count = 0;
	ret.move_count = 0;
	ret.door_pos = ini_vector();
	ret.player = create_mover('P');
	ret.size = ini_vector();
	return (ret);
}

void	clear_map(t_map map)
{
	lib_split_clean(map.matrix);
}
