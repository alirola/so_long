/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:04:04 by alirola-          #+#    #+#             */
/*   Updated: 2024/02/19 15:04:04 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	char			**map;
	char			**map_copy;
	int				lines;
	int				columns;
	int				c;
	int				e;
	int				p;
	int				enemy;
	t_point			p_position;
	t_point			e_position;
	int				c_copy;
	int				e_copy;
	int				moves;
	t_point			local_exit;
	mlx_t			*mlx;
	mlx_texture_t	*t_coin;
	mlx_image_t		*i_coin;
	mlx_texture_t	*t_floor;
	mlx_image_t		*i_floor;
	mlx_texture_t	*t_pd;
	mlx_image_t		*i_pd;
	mlx_texture_t	*t_pi;
	mlx_image_t		*i_pi;
	mlx_texture_t	*t_oe;
	mlx_image_t		*i_oe;
	mlx_texture_t	*t_ce;
	mlx_image_t		*i_ce;
	mlx_texture_t	*t_wall;
	mlx_image_t		*i_wall;
	mlx_texture_t	*t_enemy_i;
	mlx_image_t		*i_enemy_i;
	double			enemy_move_timer;
}	t_game;

int		read_map(t_game *game, char *map_name);
int		format_checker(char *map_name);
void	free_maps(t_game *game);
int		check_map(t_game *game);
int		texture_to_image(t_game *game);
int		image_to_window(t_game *game);
void	player_move(mlx_key_data_t keydata, void *param);
void	enemy_move(t_game *game);

#endif
