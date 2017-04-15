/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:46:09 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:46:10 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*s_copy;
	char	c_copy;

	s_copy = (char*)s;
	c_copy = (char)c;
	i = 0;
	while (i < n)
	{
		s_copy[i] = c_copy;
		i++;
	}
	return (s);
}
