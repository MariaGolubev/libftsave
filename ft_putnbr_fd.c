/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:03:09 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 12:50:47 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	buffer[12];

	if (fd < 0)
		return (-1);
	return (ft_putstr_fd(ft_itoa_str(buffer, n, numlen(n)), fd));
}
