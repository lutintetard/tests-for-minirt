/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:03:49 by lfournea          #+#    #+#             */
/*   Updated: 2026/04/29 11:26:58 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_FUNCTIONS_H
# define MATH_FUNCTIONS_H

# include <math.h>
# include "../srcs/minirt.h"

//Basic Vec Operations
t_vector	add_vector(t_vector vec1, t_vector vec2);
t_vector	sub_vectors(t_vector vec1, t_vector vec2);
t_vector	mult_vec_const(double float value, t_vector vec);
t_vector	div_vec_const(double float value, t_vector vec);

//Vector length
double float	vector_length(t_vector vec);
t_vector	normalized_vector(t_vector vec);

//Dot Product
double float	dot_product(t_vector vec1, t_vector vec2);
double float	dot_product_unnormed(t_vector vec1, t_vector vec2);
double float	associated_angle_rad(double float val);
double float	associated_angle_deg(double float val);

//Vector Product
t_vector	vector_product_unnormed(t_vector vec1, t_vector vec2);
t_vector	vector_product(t_vector vec1, t_vector vec2);

#endif
