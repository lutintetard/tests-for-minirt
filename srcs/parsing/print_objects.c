/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:27:45 by tparis            #+#    #+#             */
/*   Updated: 2026/04/28 15:14:45 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdio.h>

void	print_coord(t_coord c)
{
	printf("(%f, %f, %f)", c.x, c.y, c.z);
}

void	print_vector(t_vector v)
{
	printf("(%f, %f, %f)", v.x_axis, v.y_axis, v.z_axis);
}

void	print_color(t_color c)
{
	printf("rgb(%d, %d, %d)", c.r, c.g, c.b);
}

void	print_list_objects(t_node *node_list)
{
	t_objects	*obj;

	while (node_list)
	{
		obj = (t_objects *)node_list->structure;
		if (obj->object_type == SPHERE)
		{
			t_sphere *s = (t_sphere *)obj->object;

			printf("SPHERE\n");
			printf("  coord: ");
			print_coord(*s->coord);
			printf("\n");

			printf("  diameter: %f\n", s->diameter);

			printf("  color: ");
			print_color(*s->color);
			printf("\n");
		}
		else if (obj->object_type == PLANE)
		{
			t_plane *p = (t_plane *)obj->object;

			printf("PLANE\n");
			printf("  coord: ");
			print_coord(*p->coord);
			printf("\n");

			printf("  normal: ");
			print_vector(*p->normal_vector);
			printf("\n");

			printf("  color: ");
			print_color(*p->color);
			printf("\n");
		}
		else if (obj->object_type == CYLINDER)
		{
			t_cylinder *c = (t_cylinder *)obj->object;

			printf("CYLINDER\n");
			printf("  coord: ");
			print_coord(*c->coord);
			printf("\n");

			printf("  axis: ");
			print_vector(*c->axis_vector);
			printf("\n");

			printf("  diameter: %f\n", c->diameter);
			printf("  height: %f\n", c->height);

			printf("  color: ");
			print_color(*c->color);
			printf("\n");
		}
		else if (obj->object_type == CAM)
		{
			t_camera *cam = (t_camera *)obj->object;

			printf("CAMERA\n");
			printf("  coord: ");
			print_coord(*cam->coord);
			printf("\n");

			printf("  orientation: ");
			print_vector(*cam->orientation_vector);
			printf("\n");

			printf("  fov: %f\n", cam->fov);
		}
		else if (obj->object_type == LIGHT)
		{
			t_light *l = (t_light *)obj->object;

			printf("LIGHT\n");
			printf("  coord: ");
			print_coord(*l->coord);
			printf("\n");

			printf("  brightness: %f\n", l->bright_ratio);

			printf("  color: ");
			print_color(*l->color);
			printf("\n");
		}
		else if (obj->object_type == AMBIENT)
		{
			t_ambient *a = (t_ambient *)obj->object;

			printf("AMBIENT\n");
			printf("  ambient_light_ratio: %f\n", a->ambient_light_ratio);

			printf("  color: ");
			print_color(*a->color);
			printf("\n");
		}
		else
		{
			printf("UNKNOWN OBJECT\n");
		}

		printf("\n");
		node_list = node_list->next;
	}
}