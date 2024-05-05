# Name of the project
NAME = libftprintf.a

# Function files
SRCS =  ft_printf.c ft_putnbr.c ft_putstr.c ft_putchar.c
SRCS += ft_putnbr_uns.c ft_putnbr_base.c
SRCS += ft_putx.c ft_put_cx.c

# Function Objects
SRCS_OBJS = $(SRCS:.c=.o)

# Compiler
CC = cc

# Compiler Flags
C_FLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	ar -r $@ $^

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
