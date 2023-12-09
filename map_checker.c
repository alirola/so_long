/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:34:29 by alirola-          #+#    #+#             */
/*   Updated: 2023/12/09 14:34:29 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	format_checker(char *map_name)
{
	int	i;

	i = 0;
	i = ft_strlen(map_name);
	if ((map_name[i - 1] == 'r' && map_name[i - 2] == 'e')
		&& (map_name[i - 3] == 'b' && map_name[i - 4] == '.'))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
