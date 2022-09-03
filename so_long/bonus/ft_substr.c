/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:48:06 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/06/17 21:42:13 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m;

	if (!s)
		return (NULL);
	if ((int)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	while (start)
	{
		if (!*s)
			return (0);
		s++;
		start--;
	}
	m = (void *)malloc(sizeof(const char) * (len + 1));
	if (!m)
		return (0);
	ft_memcpy (m, s, len);
	m[len] = 0;
	return (m);
}
