/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:10:57 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 13:45:28 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ctxfree(t_ctx *ctx, void *ptr)
{
	if (!ctx || !ptr)
		return ;
	ft_ptrlist_dellone(&ctx->ptrs, ptr);
}

void	ft_free(void *ptr)
{
	ft_ctxfree(ft_ctx_get(), ptr);
}
