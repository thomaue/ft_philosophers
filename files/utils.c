/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 00:29:06 by tauer             #+#    #+#             */
/*   Updated: 2024/06/10 16:09:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <all.h>

bool	ft_atoi(const char *str, long *out_value, bool is_time)
{
	int	sign;
	int	value;
	int	i;

	value = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (*out_value = -1, false);
	while (str[i] && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		if (value > (__INT_MAX__ - str[i] + '0') / 10)
			return (*out_value = -1, false);
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	if (is_time)
		return (*out_value = (value * sign) * 1e3, true);
	return (*out_value = (value * sign), true);
}

long	get_time(t_metric code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	else if (code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (code == MILLISECOND)
		return ((tv.tv_sec * 1e3 + tv.tv_usec / 1e3));
	else if (code == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	return (-1);
}
