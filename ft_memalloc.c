/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:47:09 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/05 19:47:28 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)(malloc(size));
	if (str)
	{
		while (i < size)
			str[i++] = 0;
		return ((void *)str);
	}
	else
		return (NULL);
}
