/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:56:58 by fltorren          #+#    #+#             */
/*   Updated: 2024/08/26 17:42:23 by fltorren         ###   ########.fr       */
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

double	min_2(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

void	error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	expect(char *line, int i, char c)
{
	if (line[i] == '\0')
		error("Unexpected EOF");
	if (line[i] != c)
		error("Expected character not found");
}
