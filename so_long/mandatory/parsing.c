/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:49:57 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/18 15:49:32 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

int	map_validation(int argc, char *file)
{
	if (argc == 1)
	{
		write_text(" Error\n no args\n");
		exit (1);
	}
	if (argc > 2)
	{
		write_text(" Error\n only the first file would be used\n");
		exit (1);
	}
	if (!ft_strend_cmp(file, ".ber"))
	{
		write_text(" Error\n map should be a .ber file\n");
		exit (1);
	}
	return (1);
}

int	check_rectangle(char **map, t_data *game)
{
	int	y;
	int	count;

	y = 0;
	count = ft_strlen(map[y]);
	while (map[y])
	{
		if (count != ft_strlen(map[y]))
		{
			write_text("Error\n");
			fullfree(game);
			exit(0);
		}
		y++;
	}
	return (y);
}

void	check_ecp1(t_data *game, int len_x)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			check_symbol(game, y, x, len_x);
			if (game->map[y][x] == 'E')
				game->e++;
			if (game->map[y][x] == 'C')
				game->c++;
			if (game->map[y][x++] == 'P')
				game->p++;
		}
		y++;
	}
	if (game->e == 0 || game->c == 0 || game->p != 1)
	{
		write_text("Error\n");
		fullfree(game);
		exit(0);
	}
}

void	check_symbol(t_data *game, int y, int x, int len_x)
{
	char	c;

	c = game->map[y][x];
	if (c != '1' && c != '0' && c != 'C' && c != 'V' && c != 'P' && c != 'E'
		&& c != '\0')
	{
		write_text("Error\n");
		fullfree(game);
		exit(0);
	}
	if (c != '1' && (y == 0 || x == 0 || y == game->len_y
			|| x == len_x))
	{
		write_text("Error\n");
		fullfree(game);
		exit(0);
	}
}
