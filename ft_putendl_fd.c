/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:00:32 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:12:48 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

ssize_t	ft_putendl_fd(const char *s, int fd)
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
	len = ft_putstr_fd(s, fd);
	if (len < 0)
		return (-1);
	if (ft_putchar_fd('\n', fd) < 0)
		return (-1);
	return (len + 1);
}
