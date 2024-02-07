/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:35:09 by alirola-          #+#    #+#             */
/*   Updated: 2024/02/07 15:40:16 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->lines = 0;
	game->columns = 0;
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("ERROR: Faltan argumentos"), EXIT_FAILURE);
	if (format_checker(argv[1]) == EXIT_FAILURE)
		return (ft_printf("ERROR: formato de mapa incorrecto"), EXIT_FAILURE);
	game = ft_calloc(1, sizeof(t_game));
	init(game);
	if (read_map(game, argv[1]) == EXIT_FAILURE)
		return (free_maps(game), EXIT_FAILURE);
	if (map_check(game) == 1)
		return (free_maps(game), EXIT_FAILURE);
}
