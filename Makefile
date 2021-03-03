SRCS		= ft_printf.c \
			  ft_printing.c \
			  ft_flags.c \
			  ft_print_type_nb.c \
			  ft_print_type_else.c \
			  ft_print_type_utils.c \
			  convert/ft_atoi.c \
			  convert/ft_convert_base.c \
			  convert/ft_convert_base2.c \
			  convert/ft_itoa.c \
			  convert/ft_ptrtoa.c \
			  convert/ft_utoa.c \
			  libft/ft_putstr.c \
			  libft/ft_strlen.c \
			  libft/ft_strdup.c \

OBJS		= ${SRCS:.c=.o}

NAME		= cub3D

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

INC			= ./inc/

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS}  -o ${<:.c=.o} -c $< -I {INC}

${NAME}:	${OBJS}
			ar rcs ${NAME} $?

${OBJS}:	ft_printf.h

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
