#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/13 17:05:32 by adaly             #+#    #+#              #
#    Updated: 2017/11/24 14:32:47 by adaly            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf

SRCS = \
		main.c			\
		read.c			\
		movement.c		\
		io.c			\
		timing.c		\
		actors.c		\
		rays.c			\
		framebuffer_ops.c\
		rendering.c		\
		phys.c			\
		maneuver.c

all: $(NAME)

$(NAME): lib mlx

	@cd src && clang -Wall -Wextra -Werror -c $(SRCS) -g
	cd src && clang $(SRCS:.c=.o) -g -L../minilibx -lmlx -framework OpenGL -framework Appkit -L../libft -lftprintf -o $(NAME)
	mv src/wolf .

lib:
	@cd libft && make

mlx:
	@cd minilibx && make

clean:
	@cd libft && make clean
	@cd minilibx && make clean
	@cd src && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@/bin/rm -f $(NAME)

re: fclean all
