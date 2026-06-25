/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:31:02 by tparis            #+#    #+#             */
/*   Updated: 2026/06/25 15:16:40 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

int	main(int argc, char **argv)
{
	t_node	*scene;
	t_node	*ambient;
	t_node	*obj_list;

	if (argc != 2)
		return (1);
	//chope tous les objets
	scene = parse_scene(argv[1]);
	//cree liste objets (hors camera ambiance scene (pas de realloc))
	obj_list = copy_list_obj(scene);
	//retourne le premier noeud de la chaine demandee
	ambient = find_shape(scene, AMBIENT);
	if (!scene || !ambient)
		return (1);
	printf("#--- Before ambient light ---#\n");
	print_scene(scene);
	//calcule les couleurs des objets selon la lumiere d'ambiance
	apply_ambient(scene, ambient->obj);
	printf("\n#--- After ambient light ---#\n");
	print_scene(scene);
	printf("\n#--- Only obj ---#\n");
	print_scene(obj_list);
	//free la liste de nodes (0: que les noeuds, 1: noeuds et =objets))
	free_scene(obj_list, 0);
	free_scene(scene, 1);
	return (0);
}
