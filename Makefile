NAME = miniRT

# Directories
S_DIR = src
O_DIR = obj
M_DIR = mlx

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CLINKS = -Iinc -L$(M_DIR) -lmlx -lXext -lX11 -lm

# Libs
L_MLX = $(M_DIR)/libmlx.a

D_MTH = $(S_DIR)/math
S_MTH = \
	$(D_MTH)/math.c \
	$(D_MTH)/vector/vec.c \
	$(D_MTH)/vector/vec_op.c \
	$(D_MTH)/vector/vec_debug.c \
	$(D_MTH)/point/point.c \

D_WIN = $(S_DIR)/win
S_WIN = \
	$(D_WIN)/win.c \
	$(D_WIN)/win_event.c \
	$(D_WIN)/win_img.c \
	$(D_WIN)/win_pixel.c \

SRC = \
	$(S_DIR)/main.c \
	$(S_MTH) \
	$(S_WIN) \

OBJ = $(addprefix $(O_DIR)/, $(SRC:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< $(CLINKS) -o $@

$(NAME): $(L_MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(CLINKS)

$(L_MLX):
	@if [ ! -d "$(M_DIR)" ]; then \
		git clone https://github.com/42paris/minilibx-linux.git $(M_DIR); \
	fi
	$(MAKE) -C $(M_DIR)

all: $(NAME)

clean:
	rm -rf $(O_DIR)

fclean: clean
	@if [ -d "$(M_DIR)" ]; then \
		$(MAKE) -C $(M_DIR) clean; \
	fi
	rm -f $(NAME)

re: fclean all

# Test rules
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

run: all clean
	@./$(NAME) $(SCENE_DIR)/$(FILE)

leak: all clean
	@valgrind $(VFLAGS) ./$(NAME) $(SCENE_DIR)/$(FILE)

.phony: all clean fclean re