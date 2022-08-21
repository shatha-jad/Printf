NAME    = libftprintf.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS    = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c \
			ft_vpointer.c ft_putnbr_unsigned.c \

OBJS    = $(SRCS:.c=.o)

$(NAME):    $(OBJS)
			ar -rcs $(NAME) $(OBJS)

all:        $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all