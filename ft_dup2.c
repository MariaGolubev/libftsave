/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dup2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 20:27:13 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:28:31 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ctxdup2(t_ctx *ctx, int fd, int fd2)
{
	if (!ctx || fd < 0 || fd >= FD_SETSIZE || fd2 < 0 || fd2 >= FD_SETSIZE)
		return (-1);
	if (dup2(fd, fd2) == -1)
		return (-1);
	ctx->fds[fd2] = fd2;
	return (fd2);
}