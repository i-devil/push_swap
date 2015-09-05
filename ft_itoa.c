/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:49:57 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/05 19:50:00 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_count(int n)
{
	int			j;

	j = 0;
	while (n /= 10)
		j++;
	return (j + 1);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_itoa(int n)
{
	char		*str;
	char		*ret;
	int			len;

	len = ft_count(n);
	str = (char *)(malloc(sizeof(char) * (len + (n < 0 ? 1 : 0) + 1)));
	if (!str)
		return (NULL);
	ret = str;
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		*str++ = '-';
		n = -n;
	}
	str += len - 1;
	*(str + 1) = '\0';
	while (len--)
	{
		*str-- = (char)(n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
