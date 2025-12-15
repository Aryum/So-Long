/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:40:50 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/05 16:41:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse_main(char *arg, t_map *map_info)
{
	char	*file;

	*map_info = ini_map();
	if (!read_file(arg, &file))
		return (0);
	if (!check_split(map_info, file))
		return (0);
	if (!check_form(map_info) || !check_components(map_info))
		return (0);
	if (!check_paths(*map_info))
		return (0);
	return (1);
}
