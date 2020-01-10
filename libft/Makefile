# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 15:07:48 by vfil              #+#    #+#              #
#    Updated: 2018/01/11 17:02:13 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LSRC    =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
			ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
			ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_arriter.c ft_itoa.c \
			ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			ft_lstdelone.c ft_print_list.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_lstdelcont.c ft_strrev.c \
			ft_itoa_base.c get_next_line.c ft_chrjoin_free.c ft_strjoin_free.c \
			ft_llitoa.c ft_ulltoa.c ft_llitoa_base.c ft_ullitoa_base.c \
			ft_pow.c ft_lstappend.c

SRC	=	    ft_printf.c check_init_specification.c check_init_specification2.c \
            is_spec_elem.c prntf_chrstr.c prntf_numb.c prntf_unicode.c \
            prntf_unicode2.c buf_manager.c flag_manager.c ulltoa_base_buf.c \
            lltoa_buf.c check_color.c

PFSRC    =   $(addprefix ft_printf/, $(SRC))

OSRC   =   $(SRC:.c=.o)

LOSRC	=	$(LSRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(LSRC) $(PFSRC)
	gcc $(FLAGS) -c $(LSRC) $(PFSRC)
	ar rc $(NAME) $(LOSRC) $(OSRC)

%.o : %.c
	gcc $(FLAGS) -c $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
