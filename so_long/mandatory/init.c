/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:41:26 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/18 14:42:40 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	init_arg(t_data	*data)
{
	data->mlx = mlx_init();
	data->count = 0;
	data->count_berry = 0;
	data->step = 0;
	data->anim = 0;
	data->e = 0;
	data->c = 0;
	data->p = 0;
}

void	init_image(t_data *game)
{
	int	i;

	game->fond = mlx_xpm_file_to_image(game->mlx,
			"pict/pink.xpm",
			&i, &i);
	game->dino = mlx_xpm_file_to_image(game->mlx,
			"pict/dinosaur.xpm",
			&i, &i);
	game->water = mlx_xpm_file_to_image(game->mlx,
			"pict/swim.xpm",
			&i, &i);
	game->berry = mlx_xpm_file_to_image(game->mlx,
			"pict/strawberry.xpm",
			&i, &i);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"pict/exit.xpm",
			&i, &i);
	game->enemy_0 = mlx_xpm_file_to_image(game->mlx,
			"pict/enemy_0.xpm",
			&i, &i);
	game->enemy_1 = mlx_xpm_file_to_image(game->mlx,
			"pict/enemy_1.xpm",
			&i, &i);
}
