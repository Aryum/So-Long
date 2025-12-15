/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_frames.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:24:35 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 11:41:35 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

static int	get_xpm(void *mlx_ptr, void **ptr, char *path)
{
	int	x;
	int	y;

	x = GRID_SZ;
	y = GRID_SZ;
	*ptr = mlx_xpm_file_to_image(mlx_ptr, path, &x, &y);
	return (*ptr != NULL);
}

int	ini_frames(t_frames *frames, int count)
{
	int	i;

	frames->count = count;
	if (count > 0)
	{
		frames->sprites = lib_calloc(frames->count, sizeof(void *));
		if (frames->sprites == NULL)
			return (0);
		i = 0;
		while (i < count)
		{
			frames->sprites[i] = NULL;
			i++;
		}
	}
	else
		frames->sprites = NULL;
	return (1);
}

int	set_frames(void *mlx, t_frames *frames, int count, char *path)
{
	int		i;
	char	*current;
	size_t	len;

	if (!ini_frames(frames, count))
		return (0);
	i = 0;
	len = lib_strlen(path) + 7;
	while (i < frames->count)
	{
		current = lib_strjoin(path, "_XX.xpm");
		if (current == NULL)
			return (0);
		current[len - 5] = '0' + i % 10;
		current[len - 6] = '0' + i / 10;
		if (!get_xpm(mlx, &frames->sprites[i], current))
			return (print_f("%s\n", path), free(current), 0);
		free(current);
		i++;
	}
	return (1);
}

void	clean_frames(void *mlx, t_frames *frames)
{
	int	i;

	i = 0;
	if (frames->sprites == NULL)
		return ;
	while (i < frames->count)
	{
		if (frames->sprites[i] != NULL)
			mlx_destroy_image(mlx, frames->sprites[i]);
		i++;
	}
	lib_free(frames->sprites);
}
