/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:18:14 by ayegen            #+#    #+#             */
/*   Updated: 2023/12/19 22:54:52 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit_and_is_negative(long n)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	count++;
	return (count);
}

static void	make_job(char *str, size_t nb, int *level)
{
	if (nb > 9)
	{
		make_job(str, nb / 10, level);
		make_job(str, nb % 10, level);
	}
	else
	{
		str[*level] = nb + '0';
		(*level)++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		level;
	long	nb;

	nb = n;
	str = (char *)malloc(sizeof(char) * (count_digit_and_is_negative(nb) + 1));
	if (!str)
		return (NULL);
	level = 0;
	if (n < 0)
	{
		str[0] = '-';
		nb = nb * -1;
		level++;
	}
	make_job(str, (size_t)nb, &level);
	str[level] = '\0';
	return (str);
}
