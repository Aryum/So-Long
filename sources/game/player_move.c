/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:38:11 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/07 17:45:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	print_move(t_data *data)
{
	data->map.move_count++;
	print_f("Move count %d\n", data->map.move_count);
}

int	player_move(t_data *data, char c)
{
	if (c == '0')
		return (print_move(data), 1);
	if (c == 'C')
	{
		data->map.col_count --;
		return (print_move(data), 1);
	}
	else if (c == 'E' && data->map.col_count == 0)
	{
		print_move(data);
		print_f("BONEFIRE LIT\n");
		clean_exit(data);
	}
	return (0);
}
