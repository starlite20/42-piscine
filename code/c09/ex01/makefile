NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c\
				ft_swap.c\
				ft_putstr.c\
				ft_strlen.c\
				ft_strcmp.c

SRCS = ${addprefix ./srcs/, ${SRC:.c=.o}} 

OBJ = ${SRCS:.c=.o}

.c.o:
	${CC} ${FLAGS} -c -I includes -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	ar -rc ${NAME} ${OBJ}
	ranlib ${NAME}

all: ${NAME}

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re