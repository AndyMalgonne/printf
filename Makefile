SRCS = 	ft_printf.c \
		conversion.c \
		conversion2.c

OBJS = $(SRCS:.c=.o)
LIBFTNAME = libft.a
LIBFTDIR = ./libft
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

all: $(NAME)

$(NAME): makelibft $(OBJS)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

makelibft:
	make -C $(LIBFTDIR) bonus
	cp $(LIBFTDIR)/$(LIBFTNAME) $(LIBFTNAME) 

clean:
	$(RM) $(OBJS) a.out
	cd $(LIBFTDIR) && make clean

fclean: clean 
	$(RM) $(NAME) $(LIBFTNAME)
	cd $(LIBFTDIR) && make clean

re : fclean all

test : all
	$(CC) $(CFLAGS) test.c libftprintf.a libft.a
