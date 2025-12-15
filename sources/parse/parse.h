/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:37:51 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 10:51:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "../../helpers/printf/print.h"
# include "../data/data.h"
# define BUFFERSIZE 1

int		read_file(char *name, char **val);

int		parse_main(char *arg, t_map *map_info);

int		check_form(t_map *map);

int		check_components(t_map *map);

int		check_paths(t_map map);

int		check_split(t_map *map_info, char *file);

void	failed_dup(void);

#endif