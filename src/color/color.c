/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:27:13 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/26 15:42:49 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_color	color(int r, int g, int b)
{
	t_color	col;

	col.r = (double) r;
	col.g = (double) g;
	col.b = (double) b;
	return (col);
}

t_color	color_add(t_color a, t_color b)
{
	t_color	col;

	col.r = a.r + b.r;
	col.g = a.g + b.g;
	col.b = a.b + b.b;
	return (col);
}

t_color	color_mul(t_color a, double b)
{
	t_color	col;

	col.r = a.r * b;
	col.g = a.g * b;
	col.b = a.b * b;
	return (col);
}

int	color_to_int(t_color col)
{
	int	color;

	color = 0;
	color += ft_min((int) col.r, 255) << 16;
	color += ft_min((int) col.g, 255) << 8;
	color += ft_min((int) col.b, 255);
	return (color);
}
