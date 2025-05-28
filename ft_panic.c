/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_panic.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:58:43 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 13:06:43 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ctxpanic(t_ctx *ctx, const char *msg, int status)
{
	ft_putstr_fd("Panic!: ", STDERR_FILENO);
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	ft_ctxexit(ctx, status);
}

void	ft_panic(const char *msg, int status)
{
	ft_ctxpanic(ft_ctx_get(), msg, status);
}
