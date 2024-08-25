/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:27:13 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/25 19:34:32 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MiniRT.h"

t_color	color(int r, int g, int b)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

t_color	color_add(t_color a, t_color b)
{
	return (color(a.r + b.r, a.g + b.g, a.b + b.b));
}

t_color	color_mul(t_color a, int b)
{
	return (color(a.r * b, a.g * b, a.b * b));
}
