/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:13:28 by abidian           #+#    #+#             */
/*   Updated: 2017/12/12 18:13:31 by abidian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nbrstr(char *str, char c)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		if (*str != c && (!n || (n && *(str - 1) == c)))
			++n;
		++str;
	}
	return (n);
}

static size_t		ft_strlenc(const char *str, char c)
{
	char	*temp;

	temp = (char *)str;
	while (*str != c && *str)
		++str;
	return (str - temp);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	**temp;
	size_t	n;
	size_t	lenc;

	if (s == NULL)
		return (NULL);
	n = ft_nbrstr((char*)s, c);
	if ((str = (char**)malloc(sizeof(char*) * n + 1)) == NULL)
		return (NULL);
	temp = str;
	while (n-- > 0)
	{
		while (*s == c)
			++s;
		lenc = ft_strlenc(s, c);
		*str = ft_strsub(s, 0, lenc);
		s += lenc;
		++str;
	}
	*str = NULL;
	return (temp);
}
