/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:41:49 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/15 11:50:17 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_vec3	canvas_to_viewport(double x, double y, t_scene *scene)
{
	t_vec3	vp;

	vp.x = x * scene->camera.viewport.x / (double) scene->width;
	vp.y = y * scene->camera.viewport.y / (double) scene->height;
	vp.z = scene->camera.fov;
	return (vp);
}

void	add_light(t_scene *scene, t_generic_light light)
{
	scene->lights[scene->lights_count] = light;
	scene->lights_count++;
}

void	add_object(t_scene *scene, t_generic_object object)
{
	scene->objects[scene->objects_count] = object;
	scene->objects_count++;
}

void	draw_scene(t_scene *scene)
{
	int		x;
	int		y;
	t_vec3	dir;
	t_color	col;

	x = -scene->width / 2;
	while (x <= scene->width / 2)
	{
		y = -scene->height / 2;
		while (y <= scene->height / 2)
		{
			dir = vec3_rotate(canvas_to_viewport(x, y, scene), scene->camera.dir);
			col = trace_ray(scene->camera.pos, dir, scene, 5);
			set_pixel(scene, scene->width / 2 + x, scene->height / 2 - y,
				color_to_int(col));
			y++;
		}
		x++;
	}
}

/*	dir = canvas_to_viewport(0, -200, scene);
	col = trace_ray(scene->camera->pos, dir, scene, 3);
	ft_printf("r: %d, g: %d, b: %d\n", (int) col.r, (int) col.g, (int) col.b);*/

void	set_pixel(t_scene *scene, int x, int y, int col)
{
	int		i;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;

	data = mlx_get_data_addr(scene->img, &bpp, &size_line, &endian);
	i = (x * 4) + (y * size_line);
	if (endian == 1)
	{
		data[i] = (col >> 24);
		data[i + 1] = (col >> 16) & 0xFF;
		data[i + 2] = (col >> 8) & 0xFF;
		data[i + 3] = col & 0xFF;
	}
	else
	{
		data[i] = (col) & 0xFF;
		data[i + 1] = (col >> 8) & 0xFF;
		data[i + 2] = (col >> 16) & 0xFF;
		data[i + 3] = (col >> 24);
	}
}
