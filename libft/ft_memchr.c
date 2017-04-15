/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:44:33 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:44:34 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cur;

	str = (unsigned char *)s;
	cur = (unsigned char)c;
	while (n--)
	{
		if (*str == cur)
			return (str);
		if (n)
			str++;
	}
	return (NULL);
}
