/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:21:56 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/26 18:38:21 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

double	intersect_plane(t_vec3 pos, t_vec3 dir, t_generic_object this)
{
	double	t;
	t_vec3	vec;

	t = vec3_dot(dir, this.plane.normal_vector);
	if (fabs(t) < 1e-6)
		return (INFINITY);
	vec = vec3_sub(this.pos, pos);
	t = vec3_dot(vec, this.plane.normal_vector) / t;
	return (t);
}

t_vec3	plane_normal(t_vec3 p, t_generic_object this)
{
	(void) p;
	return (this.plane.normal_vector);
}
