/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:28:13 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/18 15:35:17 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	count_c(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->count++;
			x++;
		}
		y++;
	}
}

int	ft_exit(t_data *game)
{
	fullfree(game);
	exit(0);
	return (0);
}

void	read_fd(char **argv, t_data	*data)
{
	int		len;
	int		fd;
	char	*buf;
	char	c;

	len = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd)
		while (read(fd, &c, 1))
			len++;
	close(fd);
	buf = malloc(len + 1);
	fd = open(argv[1], O_RDONLY);
	read(fd, buf, len);
	close(fd);
	buf[len] = '\0';
	data->map = ft_split(buf, '\n');
	free(buf);
}

void	fullfree(t_data *game)
{
	int		i;

	i = -1;
	while (game->map[++i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
	}
	free(game->map);
	game->map = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	map_validation(argc, argv[1]);
	init_arg(&data);
	read_fd(argv, &data);
	data.len_y = check_rectangle(data.map, &data) - 1;
	check_ecp1(&data, ft_strlen(data.map[0]) - 1);
	data.win = mlx_new_window(data.mlx, ft_strlen(data.map[0]) * 50,
			(data.len_y + 1) * 50, "so_long");
	init_image(&data);
	count_c(&data);
	write_map(&data);
	mlx_hook(data.win, 2, (1L << 0), press_keys, &data);
	mlx_hook(data.win, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx, write_map, (void *)&data);
	mlx_loop(data.mlx);
}
