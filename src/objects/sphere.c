/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:35:28 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/25 19:46:02 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

double	intersect_sphere(t_vec3 pos, t_vec3 dir, t_generic_object this)
{
	double	coefs[3];
	t_vec3	co;
	double	delta;
	double	t[2];

	co = vec3_sub(pos, this.pos);
	coefs[0] = vec3_dot(dir, dir);
	coefs[1] = 2 * vec3_dot(dir, co);
	coefs[2] = vec3_dot(co, co) - pow(this.sphere.radius, 2);
	delta = pow(coefs[1], 2) - 4 * coefs[0] * coefs[2];
	if (delta < 0)
		return (INFINITY);
	t[0] = (-coefs[1] + sqrt(delta)) / (2 * coefs[0]);
	t[1] = (-coefs[1] - sqrt(delta)) / (2 * coefs[0]);
	if (t[0] < t[1])
		return (t[0]);
	else
		return (t[1]);
}

t_vec3	sphere_normal(t_vec3 p, t_generic_object this)
{
	return (vec3_normalize(vec3_sub(p, this.pos)));
}
