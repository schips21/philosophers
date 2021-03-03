/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schips <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:59:22 by schips            #+#    #+#             */
/*   Updated: 2020/05/30 01:04:56 by schips           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_header.h"

static long		ft_plus(const char *str, int i)
{
	long ans;

	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-2);
	return (ans);
}

int				ft_atoi(const char *nptr)
{
	int		i;
	long	ans;

	i = 0;
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = ft_plus(nptr, i);
	}
	else
		return (-2);
	if (ans > 2147483647)
		return (-2);
	return ((int)ans);
}
