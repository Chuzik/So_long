/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:30:47 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/13 19:04:59 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	*ft_memcpy(void *dest, const void	*src, size_t	n)
{
	char		*d;
	const char	*s;

	d = (char *) dest;
	s = (const char *) src;
	if (d == 0 && s == 0)
		return (0);
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
