#include "basic.h"

unsigned int	find_color_sphere(t_sphere sphere, t_ray ray)
// pour determiner le point d'intersection entre un rayon et une sphere il faut resoudre
// une equation du second degre dont les paramatres a b et c sont
// a = D^2 = 1
// b = 2D . (O - C)
// c = |O - C|^2 - R^2
// une intersection n'est possible que quand le determinant de l'expression est positif
{
	double	determinant;
	t_quadratic	quadratic;

	quadratic = find_values_of_quadratic_sphere(sphere, ray, quadratic);
	quadratic.delta = find_determinant(quadratic);
	if (quadratic.delta)
		return (0);
	return (find_intersections_sphere(quadratic, sphere));
}

t_quadratic	find_values_of_quadratic_sphere(t_sphere sphere, t_ray ray,\
t_quadratic params)
//la resolution de l'equation du second degre quand il y a intersection 
//entre un point et une sphere est 
//a = 1
//b = 2D . (O - C)
//c = | O - C | ^2 - R^2
//A VERIFIER LES RESULTATS
{
	t_vector	intermediary_step;

	params.a = 1;
	intermediary_step = point_to_vector(sub_points(ray.origin, sphere.coord));
	params.b = dot_product(mult_vec_const(2, ray.direction), intermediary_step);  
	params.c = pow(vector_length(intermediary_step), 2);
	params.c -= pow(sphere.diameter, 2);
	return (params);
}

int	 find_determinant(t_quadratic params)
//le calcul du delta est le suivant;
//delta = b^2 - 4ac
{
	params.delta = pow(params.b, 2) - (4 * params.a * params.c);
	if (params.delta < 0)
		return (1);
	return (0);
} 

unsigned int	find_intersections_sphere(t_quadratic quad, t_sphere sphere)
//pour determiner la distance il faut resoudre l'equation avec -b +/- racine delta / 2a
{
	double	distance_1;
	double	distance_2;

	distance_1 = ((-1) * (quad.b) - sqrt(quad.delta)) / (2 * quad.a);
	distance_2 = ((-1) * (quad.b) + sqrt(quad.delta)) / (2 * quad.a);
	if (distance_1 >= 0 ||  distance_2 >= 0)
		return (sphere.color);
	return (0);
}
