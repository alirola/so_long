/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:20:26 by alirola-          #+#    #+#             */
/*   Updated: 2024/02/21 16:01:23 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_images(t_game *g, int x, int y, void *img)
{
	if (g->map[g->e_position.y][g->e_position.x] == 'E')
	{
		mlx_image_to_window(g->mlx, g->i_ce, g->e_position.x * 50,
			g->e_position.y * 50);
		if (g->c == g->c_copy)
			mlx_image_to_window(g->mlx, g->i_oe, g->e_position.x * 50,
				g->e_position.y * 50);
	}
	if (g->map[g->e_position.y][g->e_position.x] != 'E'
		&& g->map[g->e_position.y][g->e_position.x] != '1')
	{
		mlx_image_to_window(g->mlx, g->i_floor, g->e_position.x * 50,
			g->e_position.y * 50);
		if (g->map[g->e_position.y][g->e_position.x] == 'C')
			mlx_image_to_window(g->mlx, g->i_coin, g->e_position.x * 50,
				g->e_position.y * 50);
	}
	if (g->map[g->e_position.y][g->e_position.x] == '1')
		mlx_image_to_window(g->mlx, g->i_wall, g->e_position.x * 50,
			g->e_position.y * 50);
	g->e_position.x = x;
	g->e_position.y = y;
	mlx_image_to_window(g->mlx, img, g->e_position.x * 50,
		g->e_position.y * 50);
}

void	calculate_direction(t_game *game, int *dx, int *dy)
{
	*dx = (game->p_position.x) - (game->e_position.x);
	*dy = (game->p_position.y) - (game->e_position.y);
}

void	direction_enemy(t_game *g, int dx, int dy)
{
	if (dx > 0)
		move_images(g, g->e_position.x + 1, g->e_position.y, g->i_enemy_i);
	if (dx < 0)
		move_images(g, g->e_position.x - 1, g->e_position.y, g->i_enemy_i);
	if (dy > 0)
		move_images(g, g->e_position.x, g->e_position.y + 1, g->i_enemy_i);
	if (dy < 0)
		move_images(g, g->e_position.x, g->e_position.y - 1, g->i_enemy_i);
}

void	enemy_move(t_game *game)
{
	int	dx;
	int	dy;

	calculate_direction(game, &dx, &dy);
	game->enemy_move_timer += game->mlx->delta_time;
	if (game->enemy_move_timer >= 0.4)
	{
		direction_enemy(game, dx, dy);
		game->enemy_move_timer = 0;
	}
	if (game->e_position.x == game->p_position.x
		&& game->e_position.y == game->p_position.y)
	{
		ft_printf("\nHas muerto\n");
		mlx_close_window(game->mlx);
	}
}