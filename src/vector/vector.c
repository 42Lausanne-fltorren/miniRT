/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:39:04 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/25 19:20:26 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vec3_scalar_mul(t_vec3 v, double m)
{
	t_vec3	new;

	new.x = v.x * m;
	new.y = v.y * m;
	new.z = v.z * m;
	return (new);
}

t_vec3	vec3_mul(t_vec3 v, t_vec3 other)
{
	t_vec3	new;

	new.x = v.x * other.x;
	new.y = v.y * other.y;
	new.z = v.z * other.z;
	return (new);
}

t_vec3	vec3_sub(t_vec3 v, t_vec3 other)
{
	t_vec3	new;

	new.x = v.x - other.x;
	new.y = v.y - other.y;
	new.z = v.z - other.z;
	return (new);
}

t_vec3	vec3_add(t_vec3 v, t_vec3 other)
{
	t_vec3	new;

	new.x = v.x + other.x;
	new.y = v.y + other.y;
	new.z = v.z + other.z;
	return (new);
}
