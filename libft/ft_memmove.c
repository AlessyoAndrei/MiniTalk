/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:50:40 by abidian           #+#    #+#             */
/*   Updated: 2017/12/11 10:52:06 by abidian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char *src;
	char *dst;

	src = (char*)str2;
	dst = (char*)str1;
	if (src < dst)
	{
		while (n--)
			dst[n] = src[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
