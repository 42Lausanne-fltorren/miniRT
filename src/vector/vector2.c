/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:17:46 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/15 12:19:07 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_vec3	vec3_normalize(t_vec3 v)
{
	t_vec3	new;
	double	len;

	len = vec3_len(v);
	new.x = v.x / len;
	new.y = v.y / len;
	new.z = v.z / len;
	return (new);
}

double	vec3_dist(t_vec3 v, t_vec3 other)
{
	t_vec3	new;

	new = vec3_sub(v, other);
	return (vec3_len(new));
}

double	vec3_len(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	vec3_dot(t_vec3 v, t_vec3 other)
{
	return (v.x * other.x + v.y * other.y + v.z * other.z);
}

t_vec3	vec3_rotate(t_vec3 v, t_vec3 rot)
{
	t_3x3_matrix	matrix;

	matrix = rotation_matrix(rot);
	return (matrix_mul_vec(matrix, v));
}
