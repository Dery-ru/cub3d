/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:39:11 by achanel           #+#    #+#             */
/*   Updated: 2022/04/05 09:39:12 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	if (j > size)
		j = size;
	if (j == size || size == 0)
		return (i + j);
	if (i < (size - j))
		ft_memcpy(dst + j, src, (i + 1));
	else
	{
		ft_memcpy(dst + j, src, (size - j - 1));
		dst[size - 1] = '\0';
	}
	return (i + j);
}
