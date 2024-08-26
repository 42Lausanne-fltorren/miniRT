/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:35:11 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/26 18:28:43 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

static double	intersect(t_generic_object obj, t_vec3 origin, t_vec3 dir)
{
	if (obj.type == SPHERE)
		return (intersect_sphere(origin, dir, obj));
	else if (obj.type == PLANE)
		return (intersect_plane(origin, dir, obj));
	else if (obj.type == CYLINDER)
		return (intersect_cylinder(origin, dir, obj));
	return (INFINITY);
}

t_intersection	compute_intersection(t_vec3 origin, t_vec3 dir, t_vec3
t_limits, t_scene *scene)
{
	t_intersection	intersection;
	int				i;
	double			tmp;

	intersection.dist = INFINITY;
	intersection.object = NULL;
	i = -1;
	while (++i < scene->objects_count)
	{
		tmp = intersect(scene->objects[i], origin, dir);
		if (tmp >= t_limits.x && tmp < t_limits.y && tmp < intersection.dist)
		{
			intersection.dist = tmp;
			intersection.object = &scene->objects[i];
		}
	}
	return (intersection);
}

static t_vec3	get_normal(t_generic_object obj, t_vec3 point)
{
	if (obj.type == SPHERE)
		return (sphere_normal(point, obj));
	else if (obj.type == PLANE)
		return (plane_normal(point, obj));
	else if (obj.type == CYLINDER)
		return (cylinder_normal(point, obj));
	return (vec3(0, 0, 0));
}

t_color	trace_ray(t_vec3 origin, t_vec3 dir, t_scene *scene, int depth)
{
	t_intersection	in;
	double			i;
	t_color			color;
	t_color			ref_color;

	in = compute_intersection(origin, dir, vec3(0.001, INFINITY, 0), scene);
	if (in.object == NULL)
		return (scene->sky_color);
	in.point = vec3_add(origin, vec3_scalar_mul(dir, in.dist));
	in.normal = get_normal(*in.object, in.point);
	in.view = vec3_scalar_mul(dir, -1);
	i = compute_lighting(in, scene);
	color = color_mul(in.object->color, i);
	if (in.object->reflective <= 0 || depth <= 0)
		return (color);
	ref_color = trace_ray(in.point,
			reflect_ray(in.view, in.normal), scene, depth - 1);
	color = color_mul(color, 1 - in.object->reflective);
	color = color_add(color, color_mul(ref_color, in.object->reflective));
	return (color);
}

t_vec3	reflect_ray(t_vec3 ray, t_vec3 normal)
{
	return (vec3_sub(vec3_scalar_mul(normal, 2 * vec3_dot(ray, normal)), ray));
}
