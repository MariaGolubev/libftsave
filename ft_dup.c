/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dup.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 20:26:29 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:29:01 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ctxdup(t_ctx *ctx, int fd)
{
	int	fd2;

	if (!ctx || fd < 0 || fd >= FD_SETSIZE)
		return (-1);
	fd2 = dup(fd);
	if (fd2 == -1)
		return (-1);
	ctx->fds[fd2] = fd2;
	return (fd2);
}

#ifdef STATIC

int	ft_dup(int fd)
{
	return (ft_ctxdup(ft_ctx(), fd));
}
#endif