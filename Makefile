# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 16:18:37 by gly               #+#    #+#              #
#    Updated: 2018/12/28 16:30:30 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls

SRC		=	ft_print_ls.c	\
			ft_print_dir.c	\
			ft_print_file.c	\
			ft_parsels.c	\
			ft_print_file_long.c	\
			ft_print_file_short.c	\
			ft_lfile_manipulators.c	\
			ft_lfile_sort.c	\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./libft/libft.a

RM		=	/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o		:	%.c
	$(CC) $(CFLAGS) -lft -L libft $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
