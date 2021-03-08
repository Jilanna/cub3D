SRCS		= ft_printf.c \
			  ft_printing.c \

OBJS		= ${SRCS:.c=.o}

NAME		= cub3D

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -rf

INC			= ./includes/

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS}  -o ${<:.c=.o} -c $< -I ${INC}

${NAME}:	${OBJS}
			${AR} ${NAME} $?

${OBJS}:	./includes/*.h

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
