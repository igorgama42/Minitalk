# FT_PRINTF PATH
FT_PRINTF_PATH = ./libraries/ft_printf

# FT_PRINTF
FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a

# SOURCE FILES
SOURCE_SERVER = server.c
SOURCE_CLIENT = client.c

# OBJECT FILES
OBJECT_SERVER = ${SOURCE_SERVER:.c=.o}
OBJECT_CLIENT = ${SOURCE_CLIENT:.c=.o}

# NAME OF THE PROGRAM
SERVER = server
CLIENT = client

# COMPILER
CC = cc

# COMPILER FLAGS
CFLAGS = -Wall -Wextra -Werror

# REMOVER
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJECT_SERVER} ${FT_PRINTF}
	${CC} ${CFLAGS} ${OBJECT_SERVER} ${FT_PRINTF} -o ${SERVER}

${CLIENT}: ${OBJECT_CLIENT} ${FT_PRINTF}
	${CC} ${CFLAGS} ${OBJECT_CLIENT} ${FT_PRINTF} -o ${CLIENT}

${FT_PRINTF}:
	${MAKE} -C ${FT_PRINTF_PATH}

clean:
	${MAKE} -C ${FT_PRINTF_PATH} clean
	${RM} ${OBJECT_SERVER} ${OBJECT_CLIENT}

fclean: clean
	${MAKE} -C ${FT_PRINTF_PATH} fclean
	${RM} ${SERVER} ${CLIENT}

re: fclean all

.PHONY: all clean fclean re libft
