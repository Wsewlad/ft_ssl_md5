# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 17:18:58 by vfil              #+#    #+#              #
#    Updated: 2018/03/13 17:18:59 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ssl
SRC		=	main.c ft_md5.c ft_sha256.c ft_sha256_part2.c
FLAGS	=	-Wall -Wextra -Werror -fsanitize=address
MYLIB	=	-L libft -lftprintf -I libft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(SRC) $(MYLIB)

clean:
	@rm -f *.o
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re:
	make re -C libft/
	make fclean
	make all
