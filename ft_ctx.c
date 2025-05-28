/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctx.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 10:59:43 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:35:25 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_ctxdestroy(t_ctx *ctx)
{
	int	i;

	if (!ctx)
		return ;
	ft_ptrlist_destroy(ctx->ptrs);
	ctx->ptrs = NULL;
	i = 0;
	while (i < MAX_FD)
	{
		if (ctx->fds[i] != -1)
		{
			close(ctx->fds[i]);
			ctx->fds[i] = -1;
		}
		i++;
	}
	if (ctx->allocated)
		free(ctx);
}

#ifdef STATIC

t_ctx	*ft_ctx(void)
{
	static t_ctx	ctx;
	static int		initialized = 0;
	int				i;

	if (!initialized)
	{
		ctx.ptrs = NULL;
		ctx.allocated = 0;
		i = 0;
		while (i < MAX_FD)
		{
			ctx.fds[i] = -1;
			i++;
		}
		initialized = 1;
	}
	return (&ctx);
}

void	ft_destroy(void)
{
	ft_ctxdestroy(ft_ctx());
}
#else

t_ctx	*ft_ctx(void)
{
	t_ctx	*ctx;
	int		i;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		return (NULL);
	ctx->ptrs = NULL;
	ctx->allocated = 1;
	i = 0;
	while (i < MAX_FD)
	{
		ctx->fds[i] = -1;
		i++;
	}
	return (ctx);
}
#endif
