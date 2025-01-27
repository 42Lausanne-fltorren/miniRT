/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:21:56 by tgajdov           #+#    #+#             */
/*   Updated: 2025/01/27 10:43:14 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

double	get_double(char *line, int *i)
{
	double	a;
	double	b;
	int		j;

	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	if (line[*i] == '\0' || (!ft_isdigit(line[*i]) && line[*i] != '-'))
		error("Invalid double");
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
	expect(line, (*i) - 1, ',');
	color.g = get_double(line, i);
	while (line[*i] && (ft_isspace(line[*i]) || line[*i] == ','))
		(*i)++;
	expect(line, (*i) - 1, ',');
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
	expect(line, *i - 1, ',');
	vec.y = get_double(line, i);
	while (line[*i] && (ft_isspace(line[*i]) || line[*i] == ','))
		(*i)++;
	expect(line, *i - 1, ',');
	vec.z = get_double(line, i);
	return (vec);
}

int	get_int(char *line, int *i)
{
	int	a;

	while (line[*i] && ft_isspace(line[*i]))
		(*i)++;
	if (line[*i] == '\0' || (!ft_isdigit(line[*i]) && line[*i] != '-'))
		error("Invalid integer");
	a = ft_atoi(line + *i);
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	return (a);
}
