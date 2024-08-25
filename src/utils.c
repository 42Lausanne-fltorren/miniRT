/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:56:58 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/25 23:58:06 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

double	min(double *arr, int n)
{
	double	m;
	int		i;

	m = INFINITY;
	i = 0;
	while (i < n)
	{
		if (arr[i] < m)
			m = arr[i];
		i++;
	}
	return (m);
}