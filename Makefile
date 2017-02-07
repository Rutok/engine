NAME = libengine.a

FLG = -Wall -Wextra -Werror

SRC = srcs/engine.c \
	  srcs/drawer.c \
	  srcs/event.c \
	  srcs/error.c \
	  srcs/keyboard_event.c \
	  srcs/camera.c \
	  srcs/matrix.c \
	  srcs/matrix_utility.c \
	  srcs/object.c \
	  srcs/scene.c \
	  srcs/triangle.c \
	  srcs/color.c \

OBJ = $(SRC:srcs/%.c=%.o)

INC = -I./includes \
	  -I./libft/includes \
	  -I/usr/include \
	  -I/usr/include/SDL2 \
	  -I/Library/Frameworks/SDL2.framework/Headers

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLG) -c $(SRC) $(INC) -O3
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(NAME)

fclean: clean
	make -C libft fclean
	rm -rf $(OBJ)

re: clean all
