/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:05:02 by abidian           #+#    #+#             */
/*   Updated: 2017/12/12 17:22:30 by abidian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char	*str;
	size_t	i;

	str = (char*)s;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
	}
}
