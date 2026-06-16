#include "basic.h"

void	centered_coord(int *x, int *y)
//fonction permet de transformer les coordonnes
//images en coordonnees repere
{
	int	x_centered;
	int	y_centered;

	x_centered = *x - WIDTH / 2;
	y_centered = (-1 * (*y)) + HEIGHT / 2;
	*x = x_centered;
	*y = y_centered;
}

void	image_coord(int *x, int *y)
//fonction permet de transformer les coordonnes
//repere en coordonnees images
{
	int	x_centered;
	int	y_centered;

	x_centered = *x + WIDTH / 2;
	y_centered = (-1) * (*y - (HEIGHT / 2));
	*x = x_centered;
	*y = y_centered;
}

/*
# include <stdlib.h>
# include <stdio.h>

int	main(int ac, char **av)
{
	int	x;
	int	y;

	x = atoi(av[1]);
	y = atoi(av[2]);

	centered_coord(&x, &y);
	printf("coord x: %d, coord y: %d\n", x, y);
	image_coord(&x, &y);
	printf("coord x: %d, coord y: %d\n", x, y);
	return (0);
}
*/
