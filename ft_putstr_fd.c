/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:01:55 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 13:05:45 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	len;

	if (!s || fd < 0)
		return (0);
	len = ft_strlen(s);
	if (len > 0)
	{
		if (write(fd, s, len) < 0)
			return (-1);
	}
	return (len);
}
