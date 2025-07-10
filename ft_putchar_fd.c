/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:00:20 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:14:56 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

ssize_t	ft_putchar_fd(char c, int fd)
{
	int result;
	
	if (fd < 0)
	{
		errno = EBADF;
		return (-1);
	}
	result = write(fd, &c, 1);
	if (result < 0)
		errno = EIO;
	return (-1);
}
