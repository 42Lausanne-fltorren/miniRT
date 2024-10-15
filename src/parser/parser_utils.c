/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:24:17 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/11 14:49:15 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_identifier	get_identifier(char *line, int *i)
{
	char	identifier[2];

	*i = 0;
	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	if (!line[*i] || !line[*i + 1])
		return (I_NONE);
	identifier[0] = line[(*i)++];
	identifier[1] = line[(*i)++];
	if (identifier[0] == 'A' && identifier[1] == ' ')
		return (I_AMBIENT_LIGHT);
	if (identifier[0] == 'C' && identifier[1] == ' ')
		return (I_CAMERA);
	if (identifier[0] == 'L' && identifier[1] == ' ')
		return (I_POINT_LIGHT);
	if (identifier[0] == 's' && identifier[1] == 'p')
		return (I_SPHERE);
	if (identifier[0] == 'p' && identifier[1] == 'l')
		return (I_PLANE);
	if (identifier[0] == 'c' && identifier[1] == 'y')
		return (I_CYLINDER);
	return (I_NONE);
}

double	get_double(char *line, int *i)
{
	double	a;
	double	b;
	int		j;

	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	a = ft_atoi(line + *i);
	while (line[*i] && (ft_isdigit(line[*i]) || line[*i] == '-'))
		(*i)++;
	if (line[*i] != '.')
		return (a);
	b = ft_atoi(line + ++(*i));
	j = *i;
	while (line[*i] && (ft_isdigit(line[*i]) || line[*i] == '-'))
		(*i)++;
	while (j < *i)
	{
		b /= 10;
		j++;
	}
	return (a + b);
}

t_color	get_color(char *line, int *i)
{
	t_color	color;

	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	color.r = get_double(line, i);
	while (line[*i] && (ft_isspace(line[*i]) || line[*i] == ','))
		(*i)++;
	color.g = get_double(line, i);
	while (line[*i] && (ft_isspace(line[*i]) || line[*i] == ','))
		(*i)++;
	color.b = get_double(line, i);
	return (color);
}

t_vec3	get_vec3(char *line, int *i)
{
	t_vec3	vec;

	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	vec.x = get_double(line, i);
	while (line[*i] && (ft_isspace(line[*i]) || line[*i] == ','))
		(*i)++;
	vec.y = get_double(line, i);
	while (line[*i] && (ft_isspace(line[*i]) || line[*i] == ','))
		(*i)++;
	vec.z = get_double(line, i);
	return (vec);
}

int	get_int(char *line, int *i)
{
	int	a;

	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	a = ft_atoi(line + *i);
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	return (a);
}
