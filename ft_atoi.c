/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:31:07 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 21:57:02 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	if (!str)
	{
		errno = EINVAL;
		return (0);
	}
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
