/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:02:40 by alirola-          #+#    #+#             */
/*   Updated: 2024/02/14 18:59:07 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->t_coin);
	mlx_delete_texture(game->t_floor);
	mlx_delete_texture(game->t_pd);
	mlx_delete_texture(game->t_pi);
	mlx_delete_texture(game->t_oe);
	mlx_delete_texture(game->t_ce);
	mlx_delete_texture(game->t_wall);
}

int	image_error(t_game *g)
{
	if (!g->t_coin || !g->t_floor || !g->t_pd || !g->t_pi || !g->t_oe
		|| !g->t_ce || !g->t_wall || !g->i_coin || !g->i_floor || !g->i_pd 
		|| !g->i_pi || !g->i_oe || !g->i_ce || !g->i_wall)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	texture_to_image(t_game *game)
{
	game->t_coin = mlx_load_png("./images/crayon.png");
	game->t_floor = mlx_load_png("./images/floor.png");
	game->t_pd = mlx_load_png("./images/ralphd.png");
	game->t_pi = mlx_load_png("./images/ralphi.png");
	game->t_ce = mlx_load_png("./images/c_door.png");
	game->t_oe = mlx_load_png("./images/o_door.png");
	game->t_wall = mlx_load_png("./images/wall.png");
	game->i_coin = mlx_texture_to_image(game->mlx, game->t_coin);
	game->i_floor = mlx_texture_to_image(game->mlx, game->t_floor);
	game->i_pd = mlx_texture_to_image(game->mlx, game->t_pd);
	game->i_pi = mlx_texture_to_image(game->mlx, game->t_pi);
	game->i_oe = mlx_texture_to_image(game->mlx, game->t_oe);
	game->i_ce = mlx_texture_to_image(game->mlx, game->t_ce);
	game->i_wall = mlx_texture_to_image(game->mlx, game->t_wall);
	clean_textures(game);
	if (image_error(game) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}