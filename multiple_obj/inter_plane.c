#include "basic.h"

int	offset_neg_coords(t_coord point)
{
	int	i;
	
	i = 0;
	if (point.x < 0)
		i++;
	if (point.y < 0)
		i++;
	if (point.z < 0)
		i++;
	return (i);
}

unsigned int	find_color_plane(t_plane plane, t_ray ray)
//dans cette fonction utiliser un produit vectoriel pour s'assurer que le vecteur 
//de vision de la camera et le plan ne sont pas confondus (possiblement une infinite de 
//reponses possibles alors
//en plusieurs lignes il faut resoudre l'equation 
//t = (p2 . n - p1 . n) / (d . n)
//ou p1 est le point d'origine du rayon d le vecteur de direction du rayon 
//p2 est le point du plan et n la vecteur orthogonal au plan
{
	double		dire_plane;
	double		distance;

	dire_plane = dot_product(ray.direction, plane.normal_vector);
	if (dire_plane == 0)
	{
		t_vector	in_plane;
		double		val;

		printf("Plan: x=%f y=%f z=%f\n", plane.coord.x, plane.coord.y, plane.coord.z);
		printf("Ray: x=%f y=%f z=%f\n", ray.origin.x, ray.origin.y, ray.origin.z); 
		in_plane = vector_two_points(plane.coord, ray.origin);
		val = dot_product_unnormed(in_plane, plane.normal_vector); 
		//ici le || etait un && avant peut etre qu'il y a un soucis
		if (val < (-1 + 1.0e-6) || val > ( 1 - 1.06e-6))
			return (0);
	}
	distance = dot_product_point_vec_two(plane.coord, plane.normal_vector); 
	distance -= dot_product_point_vec_two(ray.origin, plane.normal_vector); 
	distance /= dire_plane;
	if (distance < 0)
		return (DBL_MAX);

	t_coord		intersection_point;
	int		total_neg;
	intersection_point = add_point_vector(ray.origin, mult_vec_const(distance, ray.direction));
	total_neg = offset_neg_coords(intersection_point);	
	//ne marche pas toujours tres bien parce que la pente peut se confondre avec les coordonnees
	if (((int)(intersection_point.x) + (int)(intersection_point.y) + (int)(intersection_point.z) + total_neg) % 2 == 0\
		&& PLANE_QUAD_ON)
		return (DBL_MAX);
	return (distance);
}
