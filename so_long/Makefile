# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 17:22:57 by hirebbec          #+#    #+#              #
#    Updated: 2022/06/20 18:32:40 by zhizdahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES =  main.c ft_split.c ft_substr.c ft_strlen.c parsing.c init.c\
					ft_strdup.c ft_memcpy.c ft_itoa.c put_write.c key.c
FILES_BONUS = main.c ft_split.c ft_substr.c ft_strlen.c parsing.c init.c\
					ft_strdup.c ft_memcpy.c ft_itoa.c put_write.c key.c
MAN_FILES    =    $(addprefix mandatory/, $(FILES))		
BONUS_FILES    =    $(addprefix bonus/, $(FILES_BONUS))					
OBJS = $(MAN_FILES:%.c=%.o)

OBJS_BONUS = $(BONUS_FILES:%.c=%.o)

MLX_FLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

%.o: %.c libft.h get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY:all clean fclean re bonus
