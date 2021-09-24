SRCS	=	srcs/hextostr.c srcs/strtohex.c srcs/hextxt.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

CC		=	gcc

NAME	=	hextxt

RM		=	rm -rf

.c.o:
	${CC} ${CFLAGS} -I ./includes -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
	${CC} ${CFLAGS} ${OBJS} -L . -l ft -o ${NAME}  

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
