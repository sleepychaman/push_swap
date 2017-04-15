/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:54:26 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:54:27 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	unsigned char	cara;
	int				i;

	cara = (unsigned char)c;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == cara)
			return ((char *)s + i);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
