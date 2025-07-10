/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtol.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 21:29:42 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 21:59:08 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <errno.h>

static inline const char	*parse_sign(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static inline int	char_to_digit(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_isalpha(c))
		return (ft_tolower(c) - 'a' + 10);
	return (-1);
}

static inline long	check_overflow(long res, int digit, int base, int sign)
{
	if (res > (LONG_MAX - digit) / base)
	{
		errno = ERANGE;
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (0);
}

static inline long	set_endptr(char **endptr, const char *str, const long num)
{
	if (endptr)
		*endptr = (char *)str;
	return (num);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	long	res;
	int		sign;
	int		digit;
	long	ovf;

	res = 0;
	if (!str || base < 2 || base > 36)
		return (errno = EINVAL, 0);
	while (ft_isspace(*str))
		str++;
	str = parse_sign(str, &sign);
	while (*str)
	{
		digit = char_to_digit(*str);
		if (digit < 0 || digit >= base)
			break ;
		ovf = check_overflow(res, digit, base, sign);
		if (ovf)
			return (set_endptr(endptr, str, ovf));
		res *= base + digit;
		str++;
	}
	return (set_endptr(endptr, str, res * sign));
}
