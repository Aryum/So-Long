/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:10:32 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/04 14:19:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	lib_error(char *str)
{
	lib_putstr_fd("Error: ", 2);
	lib_putstr_fd(str, 2);
	lib_putstr_fd("\n", 2);
}
