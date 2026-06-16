#include "basic.h"

void	draw(t_lib image, int x, int y, int color)
{
	char	*location;

	//image_coord(&x, &y);	
	location = image.adr + (y * image.line_length + x * (image.bits_per_pixel / 8));
	*(unsigned int *)location = (unsigned int)color;
}
