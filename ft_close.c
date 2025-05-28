/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_close.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:14:07 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:35:25 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ctxclose(t_ctx *ctx, int fd)
{
	if (!ctx || fd < 0 || fd >= MAX_FD || ctx->fds[fd] == -1)
		return ;
	close(ctx->fds[fd]);
	ctx->fds[fd] = -1;
}

void	ft_close(int fd)
{
	ft_ctxclose(ft_ctx(), fd);
}
