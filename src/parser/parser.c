/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:51:06 by tgajdov           #+#    #+#             */
/*   Updated: 2025/01/27 10:51:29 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_identifier	get_identifier(const char *line, int *i)
{
	int				j;
	char			object_type[2];
	const char		*types[] = {"A ", "C ", "L ", "sp", "pl", "cy"};
	t_identifier	identifier_tab[6];

	identifier_tab[0] = I_AMBIENT_LIGHT;
	identifier_tab[1] = I_CAMERA;
	identifier_tab[2] = I_POINT_LIGHT;
	identifier_tab[3] = I_SPHERE;
	identifier_tab[4] = I_PLANE;
	identifier_tab[5] = I_CYLINDER;
	*i = 0;
	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	if (!line[*i] || !line[*i + 1])
		return (I_NONE);
	object_type[0] = line[(*i)++];
	object_type[1] = line[(*i)++];
	j = -1;
	while (++j < 6)
		if (ft_strncmp(object_type, types[j], 2) == 0)
			return (identifier_tab[j]);
	error("Invalid identifier");
	return (I_NONE);
}

int	parser(int fd, t_scene *scene)
{
	char			*line;
	int				i;
	t_identifier	identifier;

	line = get_next_line(fd);
	while (line)
	{
		identifier = get_identifier(line, &i);
		if (identifier == I_AMBIENT_LIGHT)
			add_light(scene, parse_ambient_light(line, &i));
		else if (identifier == I_CAMERA)
			scene->camera = parse_camera(line, &i);
		else if (identifier == I_POINT_LIGHT)
			add_light(scene, parse_point_light(line, &i));
		else if (identifier == I_SPHERE)
			add_object(scene, parse_sphere(line, &i));
		else if (identifier == I_PLANE)
			add_object(scene, parse_plane(line, &i));
		else if (identifier == I_CYLINDER)
			add_object(scene, parse_cylinder(line, &i));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
