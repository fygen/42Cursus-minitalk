/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:18:58 by ayegen            #+#    #+#             */
/*   Updated: 2023/12/10 20:18:58 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return ((char *)ptr);
		ptr++;
	}
	if (*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (NULL);
}
