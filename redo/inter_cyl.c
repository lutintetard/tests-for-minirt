#include "basic.h"

t_vector		calculate_delta(t_cylinder cyl, t_ray ray)
{
	t_coord	center_base_cyl;
	t_vector delta; 

	center_base_cyl = add_point_vector(mult_vec_const( (-1) * height / 2, cyl.axis_vector)); 
	delta = vector_two_points(ray.origin, center_base_cyl);
	return (delta);
}

unsigned int	find_color_cyl(t_cylinder cyl, t_ray ray)
//L intersection d'un rayon et d'un cylindre est defini comme
//le resultat de l'equation (p - pa + vt - (va,p - pa + vt)va)2 - r2 = 0)
//en d'autres termes
//A = 1 - (d.va)2
//B = 2⋅[(d⋅Δp)−(d⋅va)(Δp⋅va)]
//C = (Δp⋅Δp)−(Δp⋅va)2−r2
{
	t_vector delta;
	t_quadratic polynome;

	delta = calculate_delta(cyl, ray);
	polynome.a = 1 - pow(dot_product_unnormed(ray.direction, cyl.axis_vector), 2); 
	polynome.b = 2 * ((dot_product(ray.direction, delta)) - (dot_product(ray.direction, cyl.axis_vector) * dot_product(delta, cyl.axis_vector)));
	polynome.c = dot_product(delta, delta) - pow(dot_product(delta, cyl.axis_vector), 2) - pow(diameter, 2);
	
}
