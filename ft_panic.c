/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_panic.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:58:43 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:11:51 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	ft_ctxpanic(t_ctx *ctx, const char *msg)
{
	if (!ctx)
	{
		errno = EINVAL;
		return ;
	}
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
