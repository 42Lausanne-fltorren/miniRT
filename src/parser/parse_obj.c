/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:16:43 by tgajdov           #+#    #+#             */
/*   Updated: 2025/01/27 10:45:11 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_camera	parse_camera(char *line, int *i)
{
	t_camera	camera;

	camera.pos = get_vec3(line, i);
	camera.dir = get_vec3(line, i);
	camera.fov = get_double(line, i) / 90.0;
	camera.viewport = vec3(1, 1, 0);
	return (camera);
}

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
