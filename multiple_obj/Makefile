# -*- Makefile -*-

PROG=minirt
COMP=cc
FLAGS=-Wall -Wextra -Werror -lmlx_Linux -lmlx -Lminilibx -Iminilibx -lXext -lX11 -lm -lz
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
	debug.c
OFILES=$(CFILES:.c=.o)
LIBMLX=minilibx/libmlx_Linux.a

all: $(PROG)

$(PROG): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) $(FLAGS) -o $(PROG) -g

%.o:%.c $(LIBMLX)
	$(CC) $(FLAGS) $< $(FLAGS) -c -o $@ -g 

$(LIBMLX):
	make -C minilibx

clean:
	make clean -C  minilibx
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(PROG)

re: fclean all

.PHONY: all clean fclean re
