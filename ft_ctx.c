/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctx.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 10:59:43 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 13:45:20 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_ctx	*ft_ctx_get(void)
{
	static t_ctx	ctx;
	static int		initialized = 0;
	int				i;

	if (!initialized)
	{
		ctx.ptrs = NULL;
		i = 0;
		while (i < FD_SETSIZE)
		{
			ctx.fds[i] = -1;
			i++;
		}
		initialized = 1;
	}
	return (&ctx);
}

void	ft_ctx_destroy(t_ctx *ctx)
{
	int	i;

	if (!ctx)
		return ;
	ft_ptrlist_destroy(ctx->ptrs);
	ctx->ptrs = NULL;
	i = 0;
	while (i < FD_SETSIZE)
	{
		if (ctx->fds[i] != -1)
		{
			close(ctx->fds[i]);
			ctx->fds[i] = -1;
		}
		i++;
	}
}

int	ft_ctx_register_ptr(t_ctx *ctx, void *ptr)
{
	if (!ctx)
		return (1);
	return (ft_ptrlist_prepend(&ctx->ptrs, ptr));
}

int	ft_ctx_register_fd(t_ctx *ctx, int fd)
{
	if (!ctx || fd < 0 || fd >= FD_SETSIZE || ctx->fds[fd] != -1)
		return (1);
	ctx->fds[fd] = fd;
	return (0);
}
