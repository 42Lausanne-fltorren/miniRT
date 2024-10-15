/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:12:40 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/15 12:50:18 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

/*int	main(void)
{
	t_scene				scene;
	t_camera			camera;
	t_generic_light		l[2];
	t_generic_object	o[6];

	scene.width = 600;
	scene.height = 600;
	scene.objects_count = 0;
	scene.lights_count = 0;
	scene.sky_color = color(50, 50, 50);

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
	o[2].reflective = 0.75;
	o[2].color = color(200, 200, 200);
	o[2].sphere.radius = 1;
	add_object(&scene, o[2]);

	o[3].type = SPHERE;
	o[3].pos = vec3(0, -5001, 0);
	o[3].specular = 1000;
	o[3].reflective = 0.2;
	o[3].color = color(255, 255, 0);
	o[3].sphere.radius = 0;
	add_object(&scene, o[3]);

	o[4].type = CYLINDER;
	o[4].pos = vec3(0, -1.5, 4);
	o[4].specular = 500;
	o[4].reflective = 0.2;
	o[4].color = color(255, 255, 0);
	o[4].cylinder.radius = 1;
	o[4].cylinder.height = 3;
	o[4].cylinder.axis = vec3_normalize(vec3(1, 0, 0)); // TODO maybe change that uwu
	add_object(&scene, o[4]);

	o[5].type = PLANE;
	o[5].pos = vec3(0, -1, 0);
	o[5].specular = 500;
	o[5].reflective = 0.2;
	o[5].color = color(0, 255, 255);
	o[5].plane.normal_vector = vec3_normalize(vec3(0, 1, 0));
	add_object(&scene, o[5]);

	scene.mlx = mlx_init();
	scene.win = mlx_new_window(scene.mlx, scene.width, scene.height,
			"xXMiniRTXx");
	scene.img = mlx_new_image(scene.mlx, scene.width, scene.height);
	draw_scene(&scene);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.img, 0, 0);
	mlx_loop(scene.mlx);
	return (0);
}
*/

int	close_hook(t_scene *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_scene *data)
{
	if (keycode == ESC || keycode == 0xff1b)
		return (close_hook(data));
	return (0);
}

void	init_scene(t_scene *scene)
{
	scene->width = 600;
	scene->height = 600;
	scene->objects_count = 0;
	scene->lights_count = 0;
	scene->sky_color = color(50, 50, 50);
}

int	ft_error()
{
	printf("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_scene	scene;

	if (argc != 2)
		return (ft_error());
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error());
	init_scene(&scene);
	if (parse(fd, &scene) < 0)
		return (ft_error());
	close(fd);
	scene.mlx = mlx_init();
	scene.win = mlx_new_window(scene.mlx, scene.width, scene.height,
			"xXMiniRTXx");
	scene.img = mlx_new_image(scene.mlx, scene.width, scene.height);
	draw_scene(&scene);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.img, 0, 0);
	mlx_key_hook(scene.win, key_hook, &scene);
	mlx_hook(scene.win, 17, 1L << 19, close_hook, &scene);
	mlx_loop(scene.mlx);
	return (0);
}
