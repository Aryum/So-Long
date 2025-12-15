/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:47:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/07 19:33:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

void	*get_frame(t_frames frame, int index)
{
	if (index >= frame.count)
	{
		lib_error("Frame index bigger than count");
		return (frame.sprites[0]);
	}
	return (frame.sprites[index]);
}

void	*get_anim(t_frames frame, int currentFrame)
{
	return (frame.sprites[currentFrame % frame.count]);
}
