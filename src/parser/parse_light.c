/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:18:13 by tgajdov           #+#    #+#             */
/*   Updated: 2025/01/27 10:45:20 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_generic_light	parse_ambient_light(char *line, int *i)
{
	t_generic_light	light;

	light.type = AMBIENT;
	light.intensity = get_double(line, i);
	light.color = get_color(line, i);
	return (light);
}

t_generic_light	parse_point_light(char *line, int *i)
{
	t_generic_light	light;

	light.type = POINT;
	light.point_light.pos = get_vec3(line, i);
	light.intensity = get_double(line, i);
	light.color = get_color(line, i);
	return (light);
}
