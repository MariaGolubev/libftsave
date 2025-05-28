/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:57:25 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 12:58:32 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ctxexit(t_ctx *ctx, int status)
{
	ft_ctx_destroy(ctx);
	exit(status);
}

void	ft_exit(int status)
{
	ft_ctxexit(ft_ctx_get(), status);
}
