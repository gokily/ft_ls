# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 16:18:37 by gly               #+#    #+#              #
#    Updated: 2019/04/23 15:04:56 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR	=	gly
NAME	=	ft_ls

SRC		=	ft_print_ls.c	\
			ft_print_dir.c	\
			ft_print_file.c	\
			ft_parsels.c	\
			ft_print_file_long.c	\
			ft_print_file_short.c	\
			ft_lfile_manipulators.c	\
			ft_lfile_new.c \
			ft_t_ls_manipulators.c	\
			ft_lfile_sort.c	\
			ft_lfile_sort_functions.c \
			ft_get_time.c	\
			ft_dir_error.c	\
			ft_set_colors.c \
			ft_calculate_space.c \
			ft_sort_dir_arg.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./libft/libft.a

LIBFTFLAG	=	-lft -L libft

RM		=	/bin/rm -f

all		:	$(NAME) auteur

$(NAME)	:	$(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(LIBFTFLAG) 
	
$(LIBFT) :
	make -C libft

%.o		:	%.c ./ft_ls.h
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	make -C libft clean
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME) $(LIBFT)

re		: fclean all

auteur :
	echo $(AUTHOR) > auteur
.PHONY	: all clean fclean re
