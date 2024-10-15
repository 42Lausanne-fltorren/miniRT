/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:17:46 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/15 12:55:36 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_3x3_matrix	rotation_matrix(t_vec3 rot)
{
	t_vec3			u;
	double			teta;
	t_3x3_matrix	matrix;

	u = vec3_normalize(vec3_add(rot, vec3(0, 0, 1)));
	teta = acos(vec3_dot(rot, vec3(1, 0, 1)) / vec3_len(rot));
	matrix.m[0][0] = cos(teta) + u.x * u.x * (1 - cos(teta));
	matrix.m[0][1] = u.x * u.y * (1 - cos(teta)) + u.z * sin(teta);
	matrix.m[0][2] = u.x * u.z * (1 - cos(teta)) - u.y * sin(teta);
	matrix.m[1][0] = u.y * u.x * (1 - cos(teta)) - u.z * sin(teta);
	matrix.m[1][1] = cos(teta) + u.y * u.y * (1 - cos(teta));
	matrix.m[1][2] = u.y * u.z * (1 - cos(teta)) + u.x * sin(teta);
	matrix.m[2][0] = u.z * u.x * (1 - cos(teta)) + u.y * sin(teta);
	matrix.m[2][1] = u.z * u.y * (1 - cos(teta)) - u.x * sin(teta);
	matrix.m[2][2] = cos(teta) + u.z * u.z * (1 - cos(teta));
	return (matrix);
}

t_vec3	matrix_mul_vec(t_3x3_matrix matrix, t_vec3 vec)
{
	t_vec3	new;

	new.x = matrix.m[0][0] * vec.x + matrix.m[0][1] * vec.y
		+ matrix.m[0][2] * vec.z;
	new.y = matrix.m[1][0] * vec.x + matrix.m[1][1] * vec.y
		+ matrix.m[1][2] * vec.z;
	new.z = matrix.m[2][0] * vec.x + matrix.m[2][1] * vec.y
		+ matrix.m[2][2] * vec.z;
	return (new);
}
