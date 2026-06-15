#include "basic.h"

t_vector		calculate_delta(t_cylinder cyl, t_ray ray)
{
	t_coord	center_base_cyl;
	t_vector delta; 

	center_base_cyl = add_point_vector(cyl.coord, mult_vec_const( (-1) * cyl.height / 2, cyl.axis_vector)); 
	delta = vector_two_points(center_base_cyl, ray.origin);
	return (delta);
}

t_coord		intersection_point(t_ray ray, double distance)
{
	t_coord	intersection;

	intersection = add_point_vector(ray.origin, mult_vec_const(distance, ray.direction));
	return (intersection);
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
	if (ray.direction.x_axis == 1 && ray.direction.y_axis == 0 && ray.direction.z_axis == 0)
		sleep(10);
	polynome.a = 1 - pow(dot_product_unnormed(ray.direction, cyl.axis_vector), 2); 
	polynome.b = 2 * ((dot_product(ray.direction, delta)) - (dot_product(ray.direction, cyl.axis_vector) * dot_product(delta, cyl.axis_vector)));
	polynome.c = dot_product(delta, delta) - pow(dot_product(delta, cyl.axis_vector), 2) - pow(cyl.diameter / 2, 2);
	polynome.delta = find_determinant(polynome);
	if (polynome.delta == -1)	
		return (0);
	// ici on determine les distances entre l'origine du rayon et le cylindre

	double distance1;
	double distance2;
	t_coord	inter;

	distance1 = ((-1) * (polynome.b) - sqrt(polynome.delta)) / (2 * polynome.a);
	distance2 = ((-1) * (polynome.b) + sqrt(polynome.delta)) / (2 * polynome.a);
	printf("delta: %f\n", polynome.delta);
	printf("Test length dist1: %f dist2: %f\n", distance1, distance2);
	printf("polynome a:%f b:%f c:%f\n", polynome.a, polynome.b, polynome.c);
	if (distance1 < 0 && distance2 < 0)
		return (0);
	if (distance1 > distance2 && distance2 >= 0)
		distance1 = distance2;
	double height;
	t_coord	center_bottom_face;

	center_bottom_face = add_point_vector(cyl.coord, mult_vec_const( (-1) * cyl.height / 2, cyl.axis_vector)); 
	height = (dot_product(vector_two_points(intersection_point(ray, distance1), center_bottom_face), cyl.axis_vector));
	if (height > cyl.height || height < 0)
	{
		printf("Height: %f", height);
		return (0);
	}
	return (cyl.color);
}
