/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:12:40 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/26 00:04:16 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int	main(void)
{
	t_scene				scene;
	t_camera			camera;
	t_generic_light		l[2];
	t_generic_object	o[5];

	scene.width = 600;
	scene.height = 600;
	scene.objects_count = 0;
	scene.lights_count = 0;
	scene.sky_color = color(255, 255, 255);

	camera.pos = vec3(0, 0, 0);
	camera.dir = vec3(0, 0, 0);
	camera.fov = 1.0;
	camera.viewport = vec3(1, 1, 0);
	scene.camera = &camera;

	l[0].type = AMBIENT;
	l[0].intensity = 0.5;
	add_light(&scene, l[0]);
	l[1].type = POINT;
	l[1].intensity = 0.5;
	l[1].point_light.pos = camera.pos;
	add_light(&scene, l[1]);

	o[0].type = SPHERE;
	o[0].pos = vec3(0, -1, 3);
	o[0].specular = 500;
	o[0].reflective = 0.2;
	o[0].color = color(255, 0, 0);
	o[0].sphere.radius = 1;
	add_object(&scene, o[0]);

	o[1].type = SPHERE;
	o[1].pos = vec3(-2, 0, 4);
	o[1].specular = 10;
	o[1].reflective = 0.2;
	o[1].color = color(0, 255, 0);
	o[1].sphere.radius = 1;
	add_object(&scene, o[1]);

	o[2].type = SPHERE;
	o[2].pos = vec3(2, 0, 4);
	o[2].specular = 500;
	o[2].reflective = 0.2;
	o[2].color = color(0, 0, 255);
	o[2].sphere.radius = 1;
	add_object(&scene, o[2]);

	o[3].type = SPHERE;
	o[3].pos = vec3(0, -5001, 0);
	o[3].specular = 1000;
	o[3].reflective = 0.2;
	o[3].color = color(255, 255, 0);
	o[3].sphere.radius = 5000;
	add_object(&scene, o[3]);

	o[4].type = CYLINDER;
	o[4].pos = vec3(0, -1.5, 4);
	o[4].specular = 500;
	o[4].reflective = 0.2;
	o[4].color = color(0, 255, 255);
	o[4].cylinder.radius = 1;
	o[4].cylinder.height = 3;
	o[4].cylinder.axis = vec3(0.5, 0, 0);
	add_object(&scene, o[4]);

	scene.mlx = mlx_init();
	scene.win = mlx_new_window(scene.mlx, scene.width, scene.height,
			"xXMiniRTXx");
	scene.img = mlx_new_image(scene.mlx, scene.width, scene.height);
	draw_scene(&scene);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.img, 0, 0);
	mlx_loop(scene.mlx);
	return (0);
}
