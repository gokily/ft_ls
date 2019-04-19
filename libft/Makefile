AUTHOR				= gly
NAME				= libft.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -g
INC_PATH			= incl/
INC					= $(addprefix -I, $(INC_PATH))
OBJ_PATH			= obj/
SRC_PATH			= src/
BUILD_PATH			= \
	$(SRC_CHAR_PATH) \
	$(SRC_FPF_PATH) \
	$(SRC_INT_PATH) \
	$(SRC_IO_PATH) \
	$(SRC_LST_PATH) \
	$(SRC_MEM_PATH) \
	$(SRC_READ_PATH) \
	$(SRC_STR_PATH)

SRCS				= \
	$(addprefix $(SRC_CHAR_PATH),$(SRC_CHAR)) \
	$(addprefix $(SRC_FPF_PATH),$(SRC_FPF)) \
	$(addprefix $(SRC_INT_PATH),$(SRC_INT)) \
	$(addprefix $(SRC_IO_PATH),$(SRC_IO)) \
	$(addprefix $(SRC_LST_PATH),$(SRC_LST)) \
	$(addprefix $(SRC_MEM_PATH),$(SRC_MEM)) \
	$(addprefix $(SRC_READ_PATH),$(SRC_READ)) \
	$(addprefix $(SRC_STR_PATH),$(SRC_STR))

SRC_CHAR_PATH = char/
SRC_CHAR = \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \

SRC_FPF_PATH = ft_printf/
SRC_FPF = \
	ft_add_conv.c	\
	ft_add_str.c	\
	ft_add_to_buffer.c	\
	ft_conv_cper.c	\
	ft_conv_s.c	\
	ft_conv_p.c	\
	ft_conv_d.c	\
	ft_conv_u.c	\
	ft_conv_f.c	\
	ft_printf.c	\
	ft_signed_common.c	\
	ft_unsigned_common.c	\
	ft_util.c	\

SRC_INT_PATH = int/
SRC_INT = \
	ft_atoi.c \
	ft_convertbase.c \
	ft_int_comparators.c \
	ft_intabs.c \
	ft_intlen_base.c \
	ft_intpart_double.c \
	ft_itoa.c \
	ft_ll2a.c \
	ft_longlonglen_base.c \
	ft_round_double.c \
	ft_size_tlen_base.c \
	ft_sort_inttab.c \
	ft_ull2a_base.c \
	ft_ulllen_base.c \

SRC_IO_PATH = io/
SRC_IO = \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	get_next_line.c \

SRC_LST_PATH = lst/
SRC_LST = \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstpop.c \
	ft_lstpush.c \

SRC_MEM_PATH = mem/
SRC_MEM = \
	ft_bzero.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \

SRC_STR_PATH = str/
SRC_STR = \
	ft_free_strtab.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strchrstr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoinfree.c \
	ft_strjoin_three.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strndupfree.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strskipc.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \

OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all : $(NAME) auteur

$(NAME) : $(addprefix $(OBJ_PATH), $(BUILD_PATH)) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(addprefix $(OBJ_PATH), $(BUILD_PATH)) :
	mkdir -p $@

$(OBJ_PATH)%.o	: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

auteur:
	echo $(AUTHOR) > auteur

clean :
	/bin/rm -drf $(OBJ_PATH)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

