/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:53:03 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:53:04 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s)
{
	char	*str;
	int		cnt;

	cnt = ft_strlen(s);
	if (!s || !(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}
