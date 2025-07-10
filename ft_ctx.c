/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctx.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 10:59:43 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 21:37:10 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_ctxdestroy(t_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_ptrlist_destroy(ctx->ptrs);
	ctx->ptrs = NULL;
	if (ctx->allocated)
		free(ctx);
}

void	ft_ctx_init(t_ctx *ctx)
{
	if (!ctx)
		return ;
	ctx->ptrs = NULL;
	ctx->allocated = 0;
}

#ifdef STATIC

t_ctx	*ft_ctx(void)
{
	static t_ctx	ctx;
	static int		initialized = 0;

	if (!initialized)
	{
		ft_ctx_init(&ctx);
		ctx.allocated = 0;
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
	ft_ctx_init(ctx);
	ctx->allocated = 1;
	return (ctx);
}
#endif
