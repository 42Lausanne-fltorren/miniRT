/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:49:21 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/25 20:15:56 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

static void	solve_quadratic(t_vec3 newD, t_vec3 newO, t_generic_object
this, double *t)
{
	double	delta;
	double	a;
	double	b;
	double	c;

	a = pow(newD.x, 2) + pow(newD.y, 2);
	b = 2 * (newO.x * newD.x + newO.y * newD.y);
	c = pow(newO.x, 2) + pow(newO.y, 2) - pow(this.cylinder.radius, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
	{
		t[0] = INFINITY;
		return ;
	}
	t[0] = (-b + sqrt(delta)) / (2 * a);
	t[1] = (-b - sqrt(delta)) / (2 * a);
}

static double	compute_caps(t_vec3 *new, t_vec3 pos, t_vec3 dir,
t_generic_object this)
{
	double	t[2];
	t_vec3	p[2];
	double	dist[2];

	t[0] = -new[0].z / new[1].z;
	t[1] = (this.cylinder.height - new[0].z) / new[1].z;
	p[0] = vec3_add(pos, vec3_scalar_mul(dir, t[0]));
	dist[0] = vec3_dist(p[0], this.pos);
	p[1] = vec3_add(pos, vec3_scalar_mul(dir, t[1]));
	dist[1] = vec3_dist(p[1], this.pos);
	if (dist[0] > this.cylinder.radius)
		t[0] = INFINITY;
	if (dist[1] > this.cylinder.radius)
		t[1] = INFINITY;
	return (min(t, 2));
}

double	intersect_cylinder(t_vec3 pos, t_vec3 dir, t_generic_object this)
{
	t_vec3	new[2];
	double	t[3];
	double	z[2];

	new[0] = vec3_rotate(vec3_sub(pos, this.pos), this.cylinder.axis);
	new[1] = vec3_rotate(dir, this.cylinder.axis);
	solve_quadratic(new[0], new[1], this, t);
	if (t[0] == INFINITY)
		return (INFINITY);
	z[0] = new[0].z + t[0] * new[1].z;
	z[1] = new[0].z + t[1] * new[1].z;
	if (z[0] <= 0 || z[0] >= this.cylinder.height)
		t[0] = INFINITY;
	if (z[1] <= 0 || z[1] >= this.cylinder.height)
		t[1] = INFINITY;
	t[2] = INFINITY;
	if (new[1].z != 0)
		t[2] = compute_caps(new, pos, dir, this);
	return (min(t, 4));
}

t_vec3	cylinder_normal(t_vec3 pos, t_generic_object this)
{
	t_vec3	new_pos;
	t_vec3	normal;

	new_pos = vec3_rotate(vec3_sub(pos, this.pos), this.cylinder.axis);
	if (new_pos.z > 0.01 && new_pos.z < this.cylinder.height)
		normal = vec3_normalize(vec3_sub(new_pos, vec3(0, 0, new_pos.z)));
	else if (new_pos.z >= -0.01 || new_pos.z <= 0.01)
		normal = vec3(0, 0, -1);
	else if (new_pos.z >= this.cylinder.height - 0.01
		|| new_pos.z <= this.cylinder.height + 0.01)
		normal = vec3(0, 0, 1);
	else
		normal = vec3(0, 0, 0);
	return (vec3_rotate(normal, vec3_scalar_mul(this.cylinder.axis, -1)));
}
