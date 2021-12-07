SOURCES =		ft_printf.c ft_print_variables.c

NAME =			libftprintf.a

OBJECTS	=		$(SOURCES:.c=.o)

FLAGS =			-Wall -Wextra -Werror

.PHONY: all re clean fclean

all	:			$(NAME)

#bonus :			$(B_NAME)

$(NAME)	:		$(OBJECTS)
					ar -rc $(NAME) $^

$(OBJECTS) :	$(SOURCES) ft_printf.h
					cc $(FLAGS) -c $(SOURCES)

clean :
					rm -rf $(OBJECTS)

fclean :		clean
					rm -rf $(NAME)

re:				fclean all
