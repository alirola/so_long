NAME = so_long

SRC = 

OBJ = $(src:.c = .o)

MLX_PATH = ./MLX42
MLX = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./libft 

LIBFT = $(LIBFT_PATH)/libft.a

SO_LONG = so_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs

LIB_SYS = 

RM = rm -rf

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
	$(LIB) $(SO_LONG) $(OBJ)
	$(CC) $(CFLAGS) $(SO_LONG) $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(OBJ):		src/%.o : src/%.
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)
	@make -s -C $(LIBFT_PATH)

$(MLX)
	@make -s -C $(MLX_PATH)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -s -C $(MLX_PATH)
	make clean -s -C $(LIBFT_PATH)

fclean:
	$(RM) $(NAME) $(OBJ) $(SO_LONG) $(LIBFT) $(MLX)
	make fclean -s -C $(MLX_PATH)
	make fclean -s -C $(LIBFT_PATH)

re: fclean all

solong: all clean

.PHONY: all re clean fclean solong