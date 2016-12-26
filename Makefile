NAME = libengine.a

FLG = -Wall -Wextra -Werror

SRC = srcs/engine.c \
	  srcs/drawer.c \
	  srcs/event.c \
	  srcs/error.c \

OBJ = $(SRC:srcs/%.c=%.o)

INC = -I./includes \
	  -I./libft/includes \
	  -I/usr/include \
	  -I/usr/include/SDL2

LIB = -L./libft

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLG) -c $(SRC) $(INC) $(LIB) -lm -lft -lSDL2 -O3
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(NAME)

fclean: clean
	make -C libft fclean
	rm -rf $(OBJ)

re: clean all
