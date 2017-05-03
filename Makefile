# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abara <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 14:32:55 by abara             #+#    #+#              #
#    Updated: 2016/09/12 16:13:20 by abara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = includes/libft/

LIBFTA = libft.a

SRC = fractol.c burningship.c circle.c draw.c julia.c juliab.c \
	  juliac.c juliad.c mandlebrot.c mouse.c option.c press.c \
	  render.c reset.c winfo.c zoom.c

PATH_SRC = src/

MLX = -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc -o $(NAME) $(FLAGS) $(addprefix $(PATH_SRC), $(SRC)) $(addprefix $(LIBFT), $(LIBFTA)) $(MLX)

clean:
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
