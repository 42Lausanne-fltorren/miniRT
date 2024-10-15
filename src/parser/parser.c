/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:24:17 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/11 14:58:10 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_scene	parse(int fd)
{
	t_scene			scene;
	char			*line;
	int				i;
	t_identifier	identifier;

	scene.objects_count = 0;
	scene.lights_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		identifier = get_identifier(line, &i);
		if (identifier == I_AMBIENT_LIGHT)
			add_light(&scene, parse_ambient_light(line, &i));
		else if (identifier == I_CAMERA)
			scene.camera = parse_camera(line, &i);
		else if (identifier == I_POINT_LIGHT)
			add_light(&scene, parse_point_light(line, &i));
		else if (identifier == I_SPHERE)
			add_object(&scene, parse_sphere(line, &i));
		else if (identifier == I_PLANE)
			add_object(&scene, parse_plane(line, &i));
		else if (identifier == I_CYLINDER)
			add_object(&scene, parse_cylinder(line, &i));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (scene);
}

t_camera	parse_camera(char *line, int *i)
{
	t_camera	camera;

	camera.pos = get_vec3(line, i);
	camera.dir = get_vec3(line, i);
	camera.fov = get_double(line, i) / 90.0;
	camera.viewport = vec3(1, 1, 0);
	return (camera);
}
