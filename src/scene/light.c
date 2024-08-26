/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:56:11 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/26 15:29:23 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

static double	compute_shadow(t_intersection inter, t_scene *scene,
								double t_max, t_generic_light light)
{
	t_intersection	shadow;
	double			n_dot_l;
	t_vec3			r;
	double			r_dot_v;
	double			i;

	i = 0.0;
	shadow = compute_intersection(inter.point, inter.light_vec,
			vec3(0.001, t_max, 0), scene);
	if (shadow.object != NULL)
		return (0.0);
	n_dot_l = vec3_dot(inter.normal, inter.light_vec);
	if (n_dot_l > 0)
		i += light.intensity * n_dot_l / (vec3_len(inter.normal)
				* vec3_len(inter.light_vec));
	if (inter.object->specular != -1)
	{
		r = vec3_scalar_mul(inter.normal, n_dot_l * 2);
		r = vec3_sub(r, inter.light_vec);
		r_dot_v = vec3_dot(r, inter.view);
		if (r_dot_v > 0)
			i += light.intensity * pow(r_dot_v / (vec3_len(r)
						* vec3_len(inter.view)), inter.object->specular);
	}
	return (i);
}

double	compute_lighting(t_intersection inter, t_scene *scene)
{
	double	i;
	int		j;
	double	t_max;

	i = 0.0;
	j = -1;
	while (++j < scene->lights_count)
	{
		if (scene->lights[j].type == AMBIENT)
			i += scene->lights[j].intensity;
		else
		{
			if (scene->lights[j].type == POINT)
			{
				inter.light_vec = vec3_sub(scene->lights[j].point_light.pos,
						inter.point);
				t_max = 1;
			}
			else
			{
				inter.light_vec = scene->lights[j].dir_light.dir;
				t_max = INFINITY;
			}
			i += compute_shadow(inter, scene, t_max, scene->lights[j]);
		}
	}
	return (i);
}
