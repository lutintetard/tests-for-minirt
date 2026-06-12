#include "basic.h"

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

	dire_plane = dot_product_unnormed(ray.direction, plane.normal_vector);
	if (dire_plane == 0)
		return (0x00FF0000);
	distance = dot_product_point_vec(plane.coord, plane.normal_vector); 
	distance -= dot_product_point_vec(ray.origin, plane.normal_vector); 
	distance /= dire_plane;
	if (distance < 0)
		return (0);
	t_vector intersection_point;
        intersection_point.x_axis = ray.origin.x + distance * ray.direction.x_axis;
        intersection_point.y_axis = ray.origin.y + distance * ray.direction.y_axis;
        intersection_point.z_axis = ray.origin.z + distance * ray.direction.z_axis;

        // 5. Application du damier
        // Note : On utilise les 3 axes (ou au moins X et Y si c'est un mur, X et Z si c'est un sol)
        // Pour être universel, on peut additionner les 3 axes :
        int check_x = (int)floor(intersection_point.x_axis);
        int check_y = (int)floor(intersection_point.y_axis);
        int check_z = (int)floor(intersection_point.z_axis);

        if ((check_x + check_y + check_z) % 2 == 0)
                return (0x00000000); // Noir
        else
                return (plane.color); // Couleur du pla
}
