# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:31:32 by gly               #+#    #+#              #
#    Updated: 2018/12/20 13:22:41 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c		ft_bzero.c		ft_isalnum.c	\
	  ft_ll2a.c	\
	  ft_ull2a.c	\
	  ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c	\
	  ft_itoa.c		ft_lstadd.c		ft_lstdel.c		\
	  ft_lstdelone.c	ft_lstiter.c	ft_lstmap.c		ft_lstnew.c		\
	  ft_memalloc.c	ft_memccpy.c	ft_memchr.c		ft_memcmp.c		\
	  ft_memcpy.c	ft_memdel.c		ft_memset.c		ft_memmove.c	\
	  ft_putchar.c	ft_putchar_fd.c	ft_putendl.c	ft_putendl_fd.c	\
	  ft_putnbr.c	ft_putnbr_fd.c	ft_putstr.c		ft_putstr_fd.c	\
	  ft_strcat.c	ft_strchr.c		ft_strclr.c		ft_strcmp.c		\
	  ft_strcpy.c	ft_strdel.c		ft_strdup.c		ft_strndup.c	\
	  ft_strndupfree.c	\
	  ft_strequ.c	ft_striter.c	ft_striteri.c	ft_strjoin.c	\
	  ft_strlcat.c	ft_strlen.c		ft_strmap.c		\
	  ft_strmapi.c	ft_strncat.c	ft_strncmp.c	ft_strncpy.c	\
	  ft_strnequ.c	ft_strnew.c		ft_strnstr.c	ft_strrchr.c	\
	  ft_strsplit.c	ft_strstr.c		ft_strsub.c		ft_strtrim.c	\
	  ft_strchrstr.c	ft_strjoinfree.c	\
	  ft_tolower.c	ft_toupper.c \
	  ft_intabs.c	ft_strskipc.c	ft_intlen_base.c ft_size_tlen_base.c	\
	  ft_lstlast.c	ft_lstpop.c		ft_lstpush.c	\
	  ft_convertbase.c	\
	  ft_size_t2a_base.c	\
	  ft_ull2a_base.c	\
	  ft_longlonglen_base.c	\
	  ft_ulllen_base.c	\
	  ft_intpart_double.c	\
	  ft_round_double.c	\
	  get_next_line.c	\

all: $(NAME)

OBJ = $(SRC:.c=.o)

%.o : %.c ./libft.h
	gcc -Wall -Wextra -Werror -o $@ -c $<
	#gcc -Wall -Wextra -Werror -fsanitize=address -o $@ -c $<

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

.PHONY: clean fclean re all

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
