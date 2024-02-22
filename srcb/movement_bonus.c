/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:49:39 by alirola-          #+#    #+#             */
/*   Updated: 2024/02/21 16:01:27 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	images(t_game *g, int x, int y, void *img)
{
	if (g->map[g->p_position.y][g->p_position.x] == 'E')
		mlx_image_to_window(g->mlx, g->i_ce, g->p_position.x * 50,
			g->p_position.y * 50);
	if (g->map[g->p_position.y][g->p_position.x] != 'E' &&
		g->map[g->p_position.y][g->p_position.x] != '1')
		mlx_image_to_window(g->mlx, g->i_floor,
			g->p_position.x * 50, g->p_position.y * 50);
	g->p_position.x = x;
	g->p_position.y = y;
	if (g->map[g->p_position.y][g->p_position.x] == 'C')
	{
		mlx_image_to_window(g->mlx, g->i_floor,
			g->p_position.x * 50, g->p_position.y * 50);
		g->map[g->p_position.y][g->p_position.x] = '0';
		g->c++;
		if (g->c == g->c_copy)
			mlx_image_to_window(g->mlx, g->i_oe,
				g->local_exit.x * 50, g->local_exit.y * 50);
	}
	mlx_image_to_window(g->mlx, img, g->p_position.x * 50,
		g->p_position.y * 50);
}

void	counter(t_game *g)
{
	char	*counter;

	counter = ft_itoa(g->moves);
	mlx_image_to_window (g->mlx, g->i_floor, 0, 0);
	mlx_put_string(g->mlx, counter, 15, 15);
	free(counter);
}

static void	keypress(t_game *g, int x, int y, void *img)
{
	g->moves++;
	counter(g);
	if (g->map[y][x] == 'E' && g->c == g->c_copy)
	{
		mlx_close_window(g->mlx);
		ft_printf("\nHas ganado\n");
	}
	else if (g->map[y][x] != '1')
		images (g, x, y, img);
}

void	player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y - 1, game->i_pd);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x - 1, game->p_position.y, game->i_pi);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y + 1, game->i_pd);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x + 1, game->p_position.y, game->i_pd);
}
