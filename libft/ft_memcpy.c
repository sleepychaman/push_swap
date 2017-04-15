/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:45:28 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:45:28 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	if (dst == src || n == 0)
		return (dst);
	c2 = (unsigned char *)src;
	c1 = (unsigned char *)dst;
	while (n--)
		*c1++ = *c2++;
	return (dst);
}
