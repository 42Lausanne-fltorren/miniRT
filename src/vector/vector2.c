/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:17:46 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/25 20:00:05 by fltorren         ###   ########.fr       */
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
	double	angle;
	double	pos[3];
	t_vec3	tmp;

	angle = rot.x * M_PI;
	pos[1] = v.y * cos(angle) - v.z * sin(angle);
	pos[2] = v.y * sin(angle) + v.z * cos(angle);
	tmp = vec3(v.x, pos[1], pos[2]);
	angle = rot.y * M_PI;
	pos[0] = tmp.x * cos(angle) + tmp.z * sin(angle);
	pos[2] = -tmp.x * sin(angle) + tmp.z * cos(angle);
	tmp = vec3(pos[0], tmp.y, pos[2]);
	angle = rot.z * M_PI;
	pos[0] = tmp.x * cos(angle) - tmp.y * sin(angle);
	pos[1] = tmp.x * sin(angle) + tmp.y * cos(angle);
	return (vec3(pos[0], pos[1], tmp.z));
}
