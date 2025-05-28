/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_open.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 13:16:13 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 13:30:21 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_ctxopen(t_ctx *ctx, const char *pathname, int flags, ...)
{
	va_list	args;
	int		fd;
	mode_t	mode;

	va_start(args, flags);
	if (!ctx || !pathname)
		return (-1);
	if (flags & O_CREAT)
	{
		mode = va_arg(args, mode_t);
		fd = open(pathname, flags, mode);
	}
	else
	{
		fd = open(pathname, flags);
	}
	if (fd < 0)
		return (-1);
	if (ft_ctx_register_fd(ctx, fd) != 0)
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

int	ft_open(const char *pathname, int flags, ...)
{
	va_list	args;
	int		fd;
	mode_t	mode;

	va_start(args, flags);
	if (!pathname)
		return (-1);
	if (flags & O_CREAT)
	{
		mode = va_arg(args, mode_t);
		fd = open(pathname, flags, mode);
	}
	else
	{
		fd = open(pathname, flags);
	}
	if (fd < 0)
		return (-1);
	if (ft_ctx_register_fd(ft_ctx_get(), fd) != 0)
	{
		close(fd);
		return (-1);
	}
	return (fd);
}
