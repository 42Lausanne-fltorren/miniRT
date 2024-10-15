/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:33:46 by fltorren          #+#    #+#             */
/*   Updated: 2024/10/11 14:34:31 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	while (i < (len + 1))
	{
		if (str[i] == (char) c)
			return (&((char *) str)[i]);
		i++;
	}
	return (NULL);
}
