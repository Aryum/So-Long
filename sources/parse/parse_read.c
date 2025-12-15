/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:37:40 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/07 19:02:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	safe_read(int fd, char *buffer, ssize_t *read_bytes)
{
	*read_bytes = read(fd, buffer, BUFFERSIZE);
	if (*read_bytes == -1)
		return (lib_error("Read file failed"), 0);
	else
		buffer[*read_bytes] = '\0';
	return (1);
}

static int	str_join(char **old, char *buffer)
{
	char	*temp;

	if (*old == NULL)
		temp = lib_strdup(buffer);
	else
	{
		temp = lib_strjoin(*old, buffer);
		lib_free(*old);
	}
	*old = temp;
	if (*old == NULL)
		return (lib_error("Failed in joining strings"), 0);
	return (1);
}

static int	is_valid_format(char *name)
{
	size_t	len;

	len = lib_strlen(name);
	if (len > 4 && !lib_strncmp(&(name[len - 4]), ".ber", 4))
		return (1);
	lib_error("Invalid file name");
	return (0);
}

int	read_file(char *name, char **val)
{
	int		fd;
	char	buffer[BUFFERSIZE + 1];
	ssize_t	read_bytes;

	*val = NULL;
	if (!is_valid_format(name))
		return (0);
	fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		return (lib_error("Couldn't open file"), 0);
	if (safe_read(fd, buffer, &read_bytes))
	{
		while (read_bytes > 0)
		{
			if (!str_join(val, buffer))
				return (close(fd), 0);
			if (!safe_read(fd, buffer, &read_bytes))
				return (close(fd), lib_free(*val), 0);
		}
	}
	close(fd);
	return (1);
}
