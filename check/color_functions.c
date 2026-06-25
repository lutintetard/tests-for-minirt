/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:48:38 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:15:19 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_color	hextocolor(unsigned int hex)
{
	t_color	c;

	c.r = ((hex >> 16) & 0xFF) / 255.0f;
	c.g = ((hex >> 8) & 0xFF) / 255.0f;
	c.b = (hex & 0xFF) / 255.0f;
	return (c);
}

unsigned int	colortohex(t_color c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(c.r * 255.0f);
	g = (int)(c.g * 255.0f);
	b = (int)(c.b * 255.0f);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (((r << 16) | (g << 8) | b));
}

unsigned int	calculate_color(unsigned int obj_color\
	, unsigned int light_color, double bright)
{
	t_color	rgb_obj;
	t_color	rgb_light;
	t_color	out;

	rgb_obj = hextocolor(obj_color);
	rgb_light = hextocolor(light_color);
	out.r = rgb_obj.r * (rgb_light.r * bright);
	out.g = rgb_obj.g * (rgb_light.g * bright);
	out.b = rgb_obj.b * (rgb_light.b * bright);
	return (colortohex(out));
}
