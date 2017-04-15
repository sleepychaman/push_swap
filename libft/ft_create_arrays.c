/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arrays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:38:55 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:39:00 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_create_arrays(int x, int y)
{
	void	**array;
	int		i;

	i = 0;
	if (x > 0)
	{
		array = (void **)malloc(sizeof(void *) * y);
		while (i < y)
		{
			array[i] = (void *)malloc(sizeof(void *) * x);
			i++;
		}
	}
	else
		array = (void *)malloc(sizeof(void *) * y);
	return (array);
}
