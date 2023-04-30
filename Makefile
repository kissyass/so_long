NAME		= so_long
CC			= gcc
CFLAGS		=  -g -o segfault
RM			= rm -f
SRCS	=	gnl/get_next_line_utils.c gnl/get_next_line.c ft_check.c ft_init.c ft_map.c main.c ft_utils.c
OBJS = $(SRCS:.c=.o)
INCL = -Lmlx -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra
LIBS = libft/libft.a ft_printf/libftprintf.a

.c.o:
		$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

all:	$(NAME)

$(NAME):	$(OBJS) 
			make -C libft/
			make -C ft_printf/
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCL) -o $(NAME)

clean:
		$(RM) $(OBJS) 
		make -C libft/ clean
		make -C ft_printf/ clean

fclean:	clean
		$(RM) $(NAME)
		make -C libft/ fclean
		make -C ft_printf/ fclean

re:	fclean all

.PHONY:	all clean fclean re