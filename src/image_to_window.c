/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:45:26 by alirola-          #+#    #+#             */
/*   Updated: 2024/02/14 18:59:11 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	image_to_window(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (g->map[j] != NULL)
	{
		i = 0;
		while (g->map[j][i] != '\n' && g->map[j][i] != '\0')
		{
			mlx_image_to_window (g->mlx, g->i_floor, i * 50, j * 50);
			if (g->map[j][i] == '1')
				mlx_image_to_window (g->mlx, g->i_wall, i * 50, j * 50);
			if (g->map[j][i] == 'C')
				mlx_image_to_window (g->mlx, g->i_coin, i * 50, j * 50);
			if (g->map[j][i] == 'P')
				mlx_image_to_window (g->mlx, g->i_pd, i * 50, j * 50);
			if (g->map[j][i] == 'E')
				mlx_image_to_window (g->mlx, g->i_ce, i * 50, j * 50);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}