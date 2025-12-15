/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:30:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 11:39:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_vector	ini_vector(void)
{
	t_vector	ret;

	ret.x = 0;
	ret.y = 0;
	ret.is_set = 0;
	return (ret);
}

t_vector	create_vector(int x, int y)
{
	t_vector	ret;

	ret.x = x;
	ret.y = y;
	ret.is_set = 1;
	return (ret);
}

t_mover	create_mover(char c)
{
	t_mover	ret;

	ret.id = c;
	ret.vct = ini_vector();
	return (ret);
}

void	update_mover(t_mover *mover, t_vector vector)
{
	mover->vct = vector;
}
