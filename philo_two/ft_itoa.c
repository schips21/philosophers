/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schips <schips@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:21:50 by schips            #+#    #+#             */
/*   Updated: 2021/01/10 13:37:54 by schips           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_header.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}


char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static int	numb_count(int nb)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while (nb > 9)
		{
			i++;
			nb = nb / 10;
		}
	}
	else if (nb < 0)
	{
		i++;
		while (nb < -9)
		{
			i++;
			nb = nb / 10;
		}
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (numb_count(n) + 1));
	if (str == 0)
		return (0);
	str[numb_count(n)] = 0;
	i = numb_count(n) - 1;
	neg = 0;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		neg = 1;
	}
	while (i >= neg)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
