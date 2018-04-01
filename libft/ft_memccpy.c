/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:38:58 by abidian           #+#    #+#             */
/*   Updated: 2017/12/12 17:18:59 by abidian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;
	unsigned char		c2;

	i = 0;
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	c2 = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == c2)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
