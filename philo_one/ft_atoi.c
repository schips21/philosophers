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

static int		ft_minus(const char *str, int i, int ans)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 - (str[i] - '0');
		i++;
	}
	return (ans);
}

static int		ft_plus(const char *str, int i)
{
	int ans;

	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	return (ans);
}

int				ft_atoi(const char *nptr)
{
	int i;
	int ans;

	i = 0;
	ans = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
	|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		i++;
		ans -= nptr[i] - '0';
		i++;
		ans = ft_minus(nptr, i, ans);
	}
	else if (nptr[i] == '+' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		i++;
		ans = ft_plus(nptr, i);
	}
	else if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = ft_plus(nptr, i);
	}
	return (ans);
}
