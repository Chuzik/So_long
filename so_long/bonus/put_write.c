/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:44:14 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/18 19:08:06 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	write_map(t_data	*game)
{
	int		y;
	int		x;
	char	*s;

	y = 0;
	s = ft_itoa(game->step);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image(y, x, game, game->map[y][x]);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, 3, 1, 0x4B0082, "Steps: ");
	mlx_string_put(game->mlx, game->win, 65, 1, 0x4B0082, s);
	free(s);
	return (0);
}

void	write_text(char *str)
{
	write(1, str, ft_strlen(str));
}

void	put_image_v(int y, int x, t_data	*game)
{
	if (game->anim < 100)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy_0, \
			x * 50, y * 50);
		game->anim++;
	}
	else if (game->anim >= 100)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy_1, \
			x * 50, y * 50);
		game->anim++;
		if (game->anim > 200)
			game->anim = 0;
	}
}

int	put_image(int y, int x, t_data	*game, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->water, \
			x * 50, y * 50);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->fond, \
			x * 50, y * 50);
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->dino, \
			x * 50, y * 50);
		game->x_p = x;
		game->y_p = y;
	}
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, \
			x * 50, y * 50);
	if (c == 'V')
	{
		put_image_v(y, x, game);
	}
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->berry, \
			x * 50, y * 50);
	return (1);
}
