/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:35:18 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 17:42:27 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int agrc, char **argv)
{
	t_map	map;
	t_data	data;

	if (agrc != 2)
		return (lib_error("Wrong argument count"), 0);
	if (parse_main(argv[1], &map))
	{
		data = ini_data(map);
		if (!start_window(&data))
			return (0);
	}
	else
		lib_split_clean(map.matrix);
	return (0);
}
