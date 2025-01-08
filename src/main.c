/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:12:40 by fltorren          #+#    #+#             */
/*   Updated: 2025/01/08 14:07:02 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

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

int	ft_error(void)
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
