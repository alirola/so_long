/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:34:57 by alirola-          #+#    #+#             */
/*   Updated: 2023/12/09 14:34:57 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	int		lines;
	int		columns;
	int		c;
	int		e;
	int		p;
	t_point	p_position;
	int		c_copy;
	int		e_copy;
	t_point	local_exit;
	mlx_t	*mlx;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		read_map(t_game *game, char *map_name);
int		format_checker(char *map_name);
void	free_maps(t_game *game);
int		check_map(t_game *game);

#endif
