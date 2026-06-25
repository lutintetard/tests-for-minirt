/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:30:00 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 18:12:00 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_vector	convert_coord_to_vector(t_coord coord)
{
	t_vector	vector;

	vector.x_axis = coord.x;
	vector.y_axis = coord.y;
	vector.z_axis = coord.z;
	return (vector);
}
