/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:31:38 by lfournea          #+#    #+#             */
/*   Updated: 2026/05/04 15:35:04 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_vector	find_ray(int pixel, t_win_view win, t_camera camera)
//cette fonction determine en fonction de l'indice du pixel le rayon associe
//il renvoie la structure correspondant a ce rayon
//pour des questions de lisibilite l'equation "vector = f + au + bv" est 
//decomposee en plusieurs lignes
{
	t_vector	associated_vector;

	find_offsets(pixel, win);
	associated_vector = orientation->vector;
	associated_vector = add_vector(mult_vec_const(win.offset_right, camera->right), associated_vector);
	associated_vector = add_vector(mult_vec_const(win.offset_up, camera->up), associated_vector);
	associated_vector = normalized_vector(associated_vector);
	return (associated_vector); 
}

void 	determine_scene_prop(t_win_view info,  double float deg)
//le but de cette fonction est de determiner l'offset necessaire au calcul des
//rayons associes
//dans cette fonction il faut verifier que l'on ne prend pas la moitie de la 
//valeur renseignee en parametre par l'utilisateur
{
	double float	angle_rad;
	
	angle_rad = deg * PI / 180;
	info.height = tan(angle_rad);
	info.pixel_size = 2 * info.height / WIN_HEIGHT;
	info.width = info.pixel_size * WIN_WIDTH / 2;
	return (pixel_size);
}

double float	calculate_value_pixel(t_minirt *info, int pixel, t_win_view win)
//cette fonction ne s'execute que lorsque on a obtenu le ray que l'on souhaite envoyer sur 
//la scene
{
	t_vector	associated_ray;
	t_node		*objects;

	objects = NULL;
	info->current_ray.direction = find_ray(pixel, win, info->camera);
	info->current_ray.origin = info->camera.coord; 
	find_intersections(&objects, info);
	//iterer sur chaque objet et determiner si il y a une intersection 
	//entre le rayon et la forme
	//trouver la valeur la plus faible et afficher la couleur associee
	//stocket les points d'intersection sous la forme de liste chainee
}

int	send_rays(t_minirt *info)
//cette fonction parcours les pixels selon leurs indices et lance les fonctions 
//qui determinent la couleur a afficher
{
	t_win_view	essentials;
	int	pixel_i;
	
	//completer la structure associee a la camera
	calculate_cam_directions(info->camera);	
	//determiner la largeur du pixel
	determine_scene_prop(essentials, info->camera->fov);
	pixel_i = 0;
	while (pixel_i < WIN_WIDTH * WIN_HEIGHT)
	{
		calculate_value_pixel(info, pixel_i, essentials);
		pixel_i++;
	}
	//push l'image une fois que le rendu est calcule
}
