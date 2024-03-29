/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:35:09 by alirola-          #+#    #+#             */
/*   Updated: 2024/02/21 15:51:28 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	ft_leaks(void)
{
	system("leaks -q so_long");
}*/

static void	init(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->lines = 0;
	game->columns = 0;
	game->c = 0;
	game->c_copy = 0;
	game->e = 0;
	game->e_copy = 0;
	game->p = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (ft_printf("ERROR: Faltan argumentos"), EXIT_FAILURE);
	if (format_checker(argv[1]) == EXIT_FAILURE)
		return (ft_printf("ERROR: Formato de mapa incorrecto"), EXIT_FAILURE);
	g = ft_calloc(1, sizeof(t_game));
	init(g);
	if (read_map(g, argv[1]) == EXIT_FAILURE)
		return (free_maps(g), EXIT_FAILURE);
	if (check_map(g) == 1)
		return (free_maps(g), EXIT_FAILURE);
	g->mlx = mlx_init(50 * g->columns, 50 * g->lines, "SO_LONG", false);
	if (!g->mlx)
		return (free_maps(g), EXIT_FAILURE);
	if (texture_to_image(g) == 1 || image_to_window(g) == 1)
		return (free_maps(g), ft_printf("Error imágenes\n"), EXIT_FAILURE);
	mlx_key_hook(g->mlx, &player_move, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (free_maps(g), EXIT_SUCCESS);
}
