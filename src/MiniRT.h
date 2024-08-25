/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:12:40 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/24 17:55:45 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "math.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
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
	int		obj_index;
	double	distance;
}	t_intersection;

typedef enum e_object_type
{
	SPHERE,
	CYLINDER,
	PLANE
}	t_object_type;

typedef enum e_light_type
{
	POINT_LIGHT,
	DIR_LIGHT,
	AMBIENT_LIGHT
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
	t_generic_object	*objects;
	int					objects_count;
	t_camera			camera;
	t_generic_light		*lights;
}	t_scene;

t_vec3			vec3(double x, double y, double z);
t_vec3			vec3_add(t_vec3 v, t_vec3 other);
t_vec3			vec3_sub(t_vec3 v, t_vec3 other);
t_vec3			vec3_scalar_mul(t_vec3 v, double m);
t_vec3			vec3_mul(t_vec3 v, t_vec3 other);
t_vec3			vec3_normalize(t_vec3 v);
double			vec3_len(t_vec3 v);
double			vec3_dist(t_vec3 v, t_vec3 other);

t_color			color(int r, int g, int b);
t_color			color_add(t_color a, t_color b);
t_color			color_mul(t_color a, int b);

t_sphere		sphere_create(t_vec3 pos, double r, t_color color,
					double specular, double reflective);
t_cylinder		cylinder_create(t_vec3 pos, t_vec3 axis, double r, double h,
					t_color color, double specular,
					double reflective);
t_plane			plane_create(t_vec3 pos, t_vec3 normal_vector, t_color color,
					double specular, double reflective);
t_camera		camera_create(t_vec3 pos, t_vec3 dir);
t_point_light	point_light_create(t_vec3 pos, double intensity);
t_dir_light		dir_light_create(t_vec3 dir, double intensity);
t_ambient_light	ambient_light_create(double intensity);

double			intersect_sphere(t_vec3 pos, t_vec3 dir, t_generic_object this);
t_vec3			sphere_normal(t_vec3 p, t_generic_object this);
double			intersect_cylinder(t_vec3 pos, t_vec3 dir,
					t_generic_object this);
t_vec3			cylinder_normal(t_vec3 p, t_generic_object this);
double			intersect_plane(t_vec3 pos, t_vec3 dir, t_generic_object this);
t_vec3			plane_normal(t_vec3 p, t_generic_object this);

t_vec3			canvas_to_viewport(double x, double y, t_camera camera);
t_vec3			reflect_ray(t_vec3 ray, t_vec3 normal);
t_intersection	compute_intersection(t_vec3 origin, t_vec3 dir,
					t_vec3 t_limits, t_scene scene);
#endif