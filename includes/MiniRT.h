/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:12:40 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/15 12:26:56 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "math.h"
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define ESC 0x35
# define NUM_PLUS 0xffab
# define NUM_MINUS 0xffad
# define UP 0x7e
# define DOWN 0x7d
# define LEFT 0x7b
# define RIGHT 0x7c

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_3x3_matrix
{
	double	m[3][3];
}	t_3x3_matrix;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_sphere
{
	double		radius;
}	t_sphere;

typedef struct s_cylinder
{
	double		radius;
	double		height;
	t_vec3		axis;
}	t_cylinder;

typedef struct s_plane
{
	t_vec3		normal_vector;
}	t_plane;

typedef struct s_point_light
{
	t_vec3	pos;
}	t_point_light;

typedef struct s_dir_light
{
	t_vec3	dir;
}	t_dir_light;

typedef struct s_ambient_light
{
}	t_ambient_light;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
	t_vec3	viewport;
}	t_camera;

typedef struct s_intersection
{
	struct s_generic_object	*object;
	double					dist;
	t_vec3					point;
	t_vec3					normal;
	t_vec3					view;
	t_vec3					light_vec;
}	t_intersection;

typedef enum e_object_type
{
	SPHERE,
	CYLINDER,
	PLANE
}	t_object_type;

typedef enum e_light_type
{
	POINT,
	DIRECTIONAL,
	AMBIENT
}	t_light_type;

typedef struct s_generic_object
{
	t_vec3			pos;
	t_color			color;
	double			specular;
	double			reflective;

	double			(*intersect)(t_vec3 pos, t_vec3 dir,
			struct s_generic_object this);
	t_vec3 (*normal)(t_vec3 p, struct s_generic_object this);
	t_object_type	type;
	union
	{
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_plane		plane;
	};
}	t_generic_object;

typedef struct s_generic_light
{
	double				intensity;
	t_color				color;

	t_light_type		type;
	union
	{
		t_point_light	point_light;
		t_dir_light		dir_light;
		t_ambient_light	ambient_light;
	};
}	t_generic_light;

typedef struct s_scene
{
	t_generic_object	objects[100];
	int					objects_count;
	t_camera			camera;
	t_generic_light		lights[100];
	int					lights_count;
	void				*mlx;
	void				*win;
	void				*img;
	int					width;
	int					height;
	t_color				sky_color;
}	t_scene;

typedef enum e_identifier
{
	I_AMBIENT_LIGHT,
	I_CAMERA,
	I_POINT_LIGHT,
	I_SPHERE,
	I_CYLINDER,
	I_PLANE,
	I_NONE
}	t_identifier;

t_vec3			vec3(double x, double y, double z);
t_vec3			vec3_add(t_vec3 v, t_vec3 other);
t_vec3			vec3_sub(t_vec3 v, t_vec3 other);
t_vec3			vec3_scalar_mul(t_vec3 v, double m);
t_vec3			vec3_mul(t_vec3 v, t_vec3 other);
double			vec3_dot(t_vec3 v, t_vec3 other);
t_vec3			vec3_normalize(t_vec3 v);
double			vec3_len(t_vec3 v);
double			vec3_dist(t_vec3 v, t_vec3 other);
t_vec3			vec3_rotate(t_vec3 v, t_vec3 rot);

t_vec3			matrix_mul_vec(t_3x3_matrix a, t_vec3 b);
t_3x3_matrix	rotation_matrix(t_vec3 rot);

t_color			color(int r, int g, int b);
t_color			color_add(t_color a, t_color b);
t_color			color_mul(t_color a, double b);
int				color_to_int(t_color col);

double			min(double *arr, int n);
double			min_2(double a, double b);

double			intersect_sphere(t_vec3 pos, t_vec3 dir, t_generic_object this);
t_vec3			sphere_normal(t_vec3 p, t_generic_object this);
double			intersect_cylinder(t_vec3 pos, t_vec3 dir,
					t_generic_object this);
t_vec3			cylinder_normal(t_vec3 p, t_generic_object this);
double			intersect_plane(t_vec3 pos, t_vec3 dir, t_generic_object this);
t_vec3			plane_normal(t_vec3 p, t_generic_object this);

t_vec3			canvas_to_viewport(double x, double y, t_scene *scene);
t_vec3			reflect_ray(t_vec3 ray, t_vec3 normal);
t_intersection	compute_intersection(t_vec3 origin, t_vec3 dir,
					t_vec3 t_limits, t_scene *scene);
double			compute_lighting(t_intersection inter, t_scene *scene);
t_color			trace_ray(t_vec3 origin, t_vec3 dir, t_scene *scene, int depth);
void			draw_scene(t_scene *scene);
void			set_pixel(t_scene *scene, int x, int y, int color);

void			add_light(t_scene *scene, t_generic_light light);
void			add_object(t_scene *scene, t_generic_object object);

t_scene			parse(int fd);
t_generic_light	parse_ambient_light(char *line, int *i);
t_generic_light	parse_point_light(char *line, int *i);
t_generic_object	parse_sphere(char *line, int *i);
t_generic_object	parse_plane(char *line, int *i);
t_generic_object	parse_cylinder(char *line, int *i);
t_camera		parse_camera(char *line, int *i);


t_identifier	get_identifier(char *line, int *i);
double			get_double(char *line, int *i);
t_color			get_color(char *line, int *i);
t_vec3			get_vec3(char *line, int *i);
int				get_int(char *line, int *i);
#endif