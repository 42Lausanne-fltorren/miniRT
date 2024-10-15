/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:24:17 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/11 14:56:30 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_generic_object	parse_sphere(char *line, int *i)
{
	t_generic_object	object;

	object.type = SPHERE;
	object.pos = get_vec3(line, i);
	object.sphere.radius = get_double(line, i) / 2.0;
	object.color = get_color(line, i);
	if (line[*i] == ' ')
	{
		object.specular = get_double(line, i);
		object.reflective = get_double(line, i);
	}
	return (object);
}

t_generic_object	parse_plane(char *line, int *i)
{
	t_generic_object	object;

	object.type = PLANE;
	object.pos = get_vec3(line, i);
	object.plane.normal_vector = get_vec3(line, i);
	object.color = get_color(line, i);
	if (line[*i] == ' ')
	{
		object.specular = get_double(line, i);
		object.reflective = get_double(line, i);
	}
	return (object);
}

t_generic_object	parse_cylinder(char *line, int *i)
{
	t_generic_object	object;

	object.type = CYLINDER;
	object.pos = get_vec3(line, i);
	object.cylinder.axis = get_vec3(line, i);
	object.cylinder.radius = get_double(line, i) / 2.0;
	object.cylinder.height = get_double(line, i);
	object.color = get_color(line, i);
	if (line[*i] == ' ')
	{
		object.specular = get_double(line, i);
		object.reflective = get_double(line, i);
	}
	return (object);
}
