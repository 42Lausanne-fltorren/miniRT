/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:24:17 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/15 12:55:34 by fltorren         ###   ########.fr       */
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
