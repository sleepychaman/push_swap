/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:48:37 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:48:37 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *s1, const char *s2)
{
	size_t		dest_len;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	dest_len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[i + dest_len] = s2[i];
		i++;
	}
	s1[dest_len + i] = '\0';
	return (s1);
}
