# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 16:18:37 by gly               #+#    #+#              #
#    Updated: 2019/02/22 13:58:11 by gly              ###   ########.fr        #
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
			ft_t_ls_manipulators.c	\
			ft_lfile_sort.c	\
			ft_get_time.c	\
			ft_dir_error.c	\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./libft/libft.a

LIBFTFLAG	=	-lft -L libft

RM		=	/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ft_strjoin_three.c print_t_ls.c $(LIBFTFLAG) 
	
$(LIBFT) :
	make -C libft

%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
