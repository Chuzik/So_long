/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:53:26 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/18 19:22:09 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	steps(t_data	*game, int y, int x)
{
	game->step++;
	game->map[game->y_p + y][game->x_p + x] = 'P';
	game->map[game->y_p][game->x_p] = '0';
	game->y_p = game->y_p + y;
	game->x_p = game->x_p + x;
	write_step(game);
}

void	write_step(t_data *game)
{
	char	*s;

	write_text("Steps: ");
	s = ft_itoa(game->step);
	write_text(s);
	write_text("\n");
	free(s);
}

void	steps_manage(int y, int x, t_data *game)
{
	if (game->map[game->y_p + y][game->x_p + x] != 1)
	{
		if (game->map[game->y_p + y][game->x_p + x] == '0')
		{
			steps(game, y, x);
		}
		else if (game->map[game->y_p + y][game->x_p + x] == 'C')
		{
			steps(game, y, x);
			game->count_berry++;
		}
		else if (game->map[game->y_p + y][game->x_p + x] == 'V')
		{
			fullfree(game);
			exit(0);
		}
		else if (game->map[game->y_p + y][game->x_p + x] == 'E'
			&& game->count_berry == game->count)
		{
			fullfree(game);
			write_text("WIN!!!");
			exit(0);
		}
	}
}

int	press_keys(int keycode, t_data *game)
{
	if (keycode == 0)
		steps_manage(0, -1, game);
	if (keycode == 2)
		steps_manage(0, 1, game);
	if (keycode == 13)
		steps_manage(-1, 0, game);
	if (keycode == 1)
		steps_manage(1, 0, game);
	if (keycode == 53)
	{
		fullfree(game);
		exit(0);
	}
	return (0);
}
