/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:19:38 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/20 16:55:42 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*fond;
	void	*dino;
	void	*water;
	void	*berry;
	void	*exit;
	void	*enemy_0;
	void	*enemy_1;
	int		x;
	int		y;
	int		w;
	int		h;
	char	**map;
	int		x_p;
	int		y_p;
	int		count_berry;
	int		count;
	int		step;
	int		anim;
	int		len_y;
	int		e;
	int		c;
	int		p;
}	t_data;

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dest, const void	*src, size_t	n);
char	*ft_itoa(int n);
int		map_validation(int argc, char *file);
void	check_ecp1(t_data *game, int len_x);
int		ft_strend_cmp(char *name, char *end);
void	check_symbol(t_data *game, int y, int x, int len_x);
void	write_text(char *str);
void	init_arg(t_data	*data);
void	init_image(t_data *game);
int		write_map(t_data	*game);
int		put_image(int y, int x, t_data	*game, char c);
void	put_image_v(int y, int x, t_data	*game);
void	steps_manage(int y, int x, t_data *game);
int		press_keys(int keycode, t_data *game);
void	steps(t_data	*game, int y, int x);
void	fullfree(t_data *game);
int		check_rectangle(char **map, t_data *game);
void	write_step(t_data *game);

#endif