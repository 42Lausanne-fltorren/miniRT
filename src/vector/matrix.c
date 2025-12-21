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

static t_3x3_matrix	identity_matrix(double sign)
{
	t_3x3_matrix	m;

	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = sign;
	return (m);
}

t_3x3_matrix	rotation_matrix(t_vec3 rot)
{
	t_vec3			k;
	double			c;
	double			s;
	double			klen;
	t_3x3_matrix	matrix;

	rot = vec3_normalize(rot);
	c = rot.z;
	k.x = -rot.y;
	k.y = rot.x;
	k.z = 0;
	klen = sqrt(k.x * k.x + k.y * k.y);
	if (klen < 0.0001)
		return (identity_matrix((c > 0) ? 1 : -1));
	k.x /= klen;
	k.y /= klen;
	s = klen;
	matrix.m[0][0] = c + k.x * k.x * (1 - c);
	matrix.m[0][1] = k.x * k.y * (1 - c);
	matrix.m[0][2] = k.y * s;
	matrix.m[1][0] = k.x * k.y * (1 - c);
	matrix.m[1][1] = c + k.y * k.y * (1 - c);
	matrix.m[1][2] = -k.x * s;
	matrix.m[2][0] = -k.y * s;
	matrix.m[2][1] = k.x * s;
	matrix.m[2][2] = c;
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
