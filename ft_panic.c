/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_panic.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:58:43 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:44:35 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ctxpanic(t_ctx *ctx, const char *msg)
{
	ft_putstr_fd("Panic!: ", STDERR_FILENO);
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	ft_ctxexit(ctx, 1);
}

#ifdef STATIC

void	ft_panic(const char *msg)
{
	ft_ctxpanic(ft_ctx(), msg);
}
#endif
