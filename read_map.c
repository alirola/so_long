/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:44:34 by alirola-          #+#    #+#             */
/*   Updated: 2023/12/09 14:44:34 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(map_name, 0);
	if (fd < 0)
		return (printf("Error: No se pudo abrir el mapa\n"), EXIT_FAILURE);
	if (allocate_map(line, game, fd, map_name) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
