CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = ./srcs/
CFILES = $(addprefix $(SRCS_DIR),	\
	minirt.c						\
	utils.c							\
	parsing/free_functions.c		\
	parsing/parsing.c				\
	parsing/utils.c					\
	parsing/print_objects.c			\
	parsing/new_object.c			\
	parsing/new_object2.c			\
	parsing/parse_ccv.c				\
	)

OBJS = $(CFILES:.c=.o)

LIBFT = Libft/libft.a
LIBMLX = minilibx-linux/libmlx.a
NAME = minirt

INCLUDES = -Iinclude -ILibft -Iminilibx-linux

MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
MATHFLAGS = -lm

GREEN = \x1b[0;32m
YELLOW = \x1b[0;33m
BLUE = \x1b[0;34m
RED = \x1b[0;31m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	@printf "$(BLUE)[BUILD] Compiling $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) $(MATHFLAGS) -o $(NAME)
	@printf "$(GREEN)[SUCCESS] $(NAME) compiled! ✔$(RESET)\n"

$(LIBFT):
	@$(MAKE) -C Libft

$(LIBMLX):
	@if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42paris/minilibx-linux.git minilibx-linux; \
	fi
	@$(MAKE) -C minilibx-linux

%.o: %.c
	@printf "$(YELLOW)Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C Libft
	@$(MAKE) clean -C minilibx-linux

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C Libft

re: fclean all

.PHONY: all clean fclean re
