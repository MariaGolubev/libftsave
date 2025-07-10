/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:01:55 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:14:18 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

ssize_t	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	len;

	if (s == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (fd < 0)
	{
		errno = EBADF;
		return (-1);
	}
	len = ft_strlen(s);
	if (len > 0)
	{
		if (write(fd, s, len) < 0)
		{
			errno = EIO;
			return (-1);
		}
	}
	return (len);
}
