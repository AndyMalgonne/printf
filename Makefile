SRCS = 	ft_printf.c \
		conversion.c \
		conversion2.c

OBJS = $(SRCS:.c=.o)
LIBFTNAME = libft.a
LIBFTDIR = ./libft
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	ar rcs $(NAME) $(OBJS)

libft/libft.a:
	make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS) a.out
	make -C $(LIBFTDIR) clean

fclean: clean 
	$(RM) $(NAME) $(LIBFTNAME)
	make -C $(LIBFTDIR) fclean

re : fclean all

test : all
	$(CC) $(CFLAGS) test.c libftprintf.a libft.a
