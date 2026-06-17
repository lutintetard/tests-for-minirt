#include "basic.h"

t_vector		calculate_delta(t_cylinder cyl, t_ray ray)
{
	t_coord	center_base_cyl;
	t_vector delta; 

	center_base_cyl = add_point_vector(cyl.coord, mult_vec_const((-1) * cyl.height / 2, cyl.axis_vector)); 
	delta = vector_two_points(center_base_cyl, ray.origin);
	return (delta);
}

t_coord		intersection_point(t_ray ray, double distance)
{
	t_coord	intersection;

	intersection = add_point_vector(ray.origin, mult_vec_const(distance, ray.direction));
	return (intersection);
}

bool	intersection_infinite_cyl(t_quadratic *polynome, t_ray ray, t_cylinder cyl)
{
	t_vector delta;

	delta = calculate_delta(cyl, ray);
	polynome->a = 1 - pow(dot_product_unnormed(ray.direction, cyl.axis_vector), 2); 
	polynome->b = 2 * ((dot_product(ray.direction, delta)) - (dot_product_unnormed(ray.direction, cyl.axis_vector) * dot_product(delta, cyl.axis_vector)));
	polynome->c = dot_product(delta, delta) - pow(dot_product(delta, cyl.axis_vector), 2) - pow(cyl.diameter / 2, 2);
	polynome->delta = find_determinant(*polynome);
	if (polynome->delta == -1)
		return (false);
	return (true);
}

double	intersection_finit_cyl(t_quadratic polynome, t_ray ray, t_cylinder cyl, double *distance)
{
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
	distance1 = smallest_positive(distance1, distance2);
	double height;
	t_coord	center_bottom_face;

	center_bottom_face = add_point_vector(cyl.coord, mult_vec_const( (-1) * cyl.height / 2, cyl.axis_vector)); 
	height = (dot_product(vector_two_points(center_bottom_face, intersection_point(ray, distance1)), cyl.axis_vector));
	if (height > cyl.height || height < 0)
	{
		printf("Height: %f", height);
		return (0);
	}
	*distance = distance1;
	return (1);
}

int	check_valid_cap(t_coord center_bottom_face, t_coord center_top_face, t_coord intersection_bottom, t_coord intersection_top, t_cylinder cyl) 
{
	int	smallest;
	double	smallest_valid;
	double	result;	

	smallest_valid = DBL_MAX;
	smallest = -1;
	result = distance_two_points(center_bottom_face, intersection_bottom);
	if (result < (cyl.diameter / 2))
	{
		smallest = 1;
		smallest_valid = result; 
	} 
	result = distance_two_points(center_top_face, intersection_top);
	if (result < (cyl.diameter / 2) && result < smallest_valid)
	{
		smallest = 2; 
	} 
	return (smallest);
}

void	intersection_point_cap(t_ray ray, t_cylinder cyl, double *distance)
{
	t_coord	center_bottom_face;
	t_coord	center_top_face;
	double	denom;

	
	center_bottom_face = add_point_vector(cyl.coord, mult_vec_const(cyl.height / 2, cyl.axis_vector)); 
	center_top_face = add_point_vector(cyl.coord, mult_vec_const((-1) * cyl.height / 2, cyl.axis_vector)); 
	denom = dot_product_unnormed(ray.direction, cyl.axis_vector); 
	if (fabs(denom) < 1.0e-10)
		return ;

	double	distance_to_bottom;
	distance_to_bottom = dot_product(vector_two_points(ray.origin, center_bottom_face), cyl.axis_vector) / denom;

	double	distance_to_top;
	distance_to_top = dot_product(vector_two_points(ray.origin, center_top_face), cyl.axis_vector) / denom;

	t_coord	intersection_bottom;
	intersection_bottom = add_point_vector(ray.origin, mult_vec_const(distance_to_bottom, ray.direction));

	t_coord	intersection_top;
	intersection_top = add_point_vector(ray.origin, mult_vec_const(distance_to_top, ray.direction));

	int good_distance;

	good_distance = check_valid_cap(center_bottom_face, center_top_face, intersection_bottom, intersection_top, cyl);
	if (good_distance != -1)
	{
		printf("value *distance: %f\t", *distance);
		if (good_distance == 1 && distance_to_bottom > 0 && distance_to_bottom < *distance)
		{
			*distance = distance_to_bottom;
			printf("value distance_to_bottom: %f\n", *distance); 
			return ;
		}
		if (good_distance == 2 && distance_to_top > 0 && distance_to_top < *distance)
		{
			printf("value distance_to_top: %f\n", *distance); 
			*distance = distance_to_top;
		}
	}
}

double	find_color_cyl(t_cylinder cyl, t_ray ray)
//Test 1: Intersection d'un point et d'un cylindre infini
//L intersection d'un rayon et d'un cylindre est defini comme
//le resultat de l'equation (p - pa + vt - (va,p - pa + vt)va)2 - r2 = 0)
//en d'autres termes
//A = 1 - (d.va)2
//B = 2⋅[(d⋅Δp)−(d⋅va)(Δp⋅va)]
//C = (Δp⋅Δp)−(Δp⋅va)2−r2
//Test 2 : Intersection d'un point et d'un cylindre fini
//hauteur = (q−p1)⋅va
//0 ≤ hauteur ≤ ∥p2 − p1∥
//Test 3 : Intersection d'un point et d'un couvercle
//
{
	t_quadratic polynome;
	double	distance;

	distance = DBL_MAX;
	if (intersection_infinite_cyl(&polynome, ray, cyl))
	{
		intersection_finit_cyl(polynome, ray, cyl, &distance);
	}
	//ici un bug si le couvercle est devant le point a gerer
	intersection_point_cap(ray, cyl, &distance);
	return (distance);
}
