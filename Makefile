CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a

LIB_SRCS = ft_printf.c ft_gesthexa.c ft_gestchar.c ft_gestint.c
 
LIB_OBJS =  $(LIB_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(LIB_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re