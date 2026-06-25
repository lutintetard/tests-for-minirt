# -*- Makefile -*-

PROG=minirt
COMP=cc
FLAGS=-Wall -Wextra -Werror -lmlx_Linux -lmlx -Lminilibx -Iminilibx -LLibft -ILibft -Llibft -lft -lXext -lX11 -lm -lz
CFILES=basic_math.c\
	basic_vector_operations.c\
	cam_directions.c\
	dot_product.c\
	draw_to_image.c\
	inter_cyl.c\
	inter_plane.c\
	light.c\
	manipulate_image_coordinates.c\
	minirt.c\
	point_math.c\
	send_rays.c\
	sphere.c\
	vector_length.c\
	vector_product.c\
	debug.c\
	parsing_input/atof.c\
	parsing_input/free_functions.c\
	parsing_input/parse_ambient.c\
	parsing_input/parse_camera.c\
	parsing_input/parse_color.c\
	parsing_input/parse_coord.c\
	parsing_input/parse_cylinder.c\
	parsing_input/parse_light.c\
	parsing_input/parse_plane.c\
	parsing_input/parse_sphere.c\
	parsing_input/parsing.c\
	parsing_input/read_file.c\
	parsing_input/utils.c\
	parsing_input/vector_utils.c\
	check/apply_ambient.c\
	check/checker.c\
	check/color_functions.c\
	check/sort_obj.c\
	check/utils.c
OFILES=$(CFILES:.c=.o)
LIBMLX=minilibx/libmlx_Linux.a
LIBFT=Libft/libft.a

all: $(PROG)

$(PROG): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) $(FLAGS) -o $(PROG) -g

%.o:%.c $(LIBMLX) $(LIBFT)
	$(CC) $(FLAGS) $< $(FLAGS) -c -o $@ -g 

$(LIBMLX):
	make -C minilibx

$(LIBFT):
	make -C Libft
clean:
	make clean -C  minilibx
	make clean -C Libft
	rm -rf $(OFILES)

fclean: clean
	make fclean -C Libft
	rm -rf $(PROG)

re: fclean all

.PHONY: all clean fclean re
