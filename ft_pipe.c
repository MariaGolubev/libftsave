/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pipe.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 20:23:07 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:25:31 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ctxpipe(t_ctx *ctx, int *fds)
{
	int	ret;

	if (!ctx || !fds)
		return (-1);
	ret = pipe(fds);
	if (ret == -1)
		return (-1);
	ctx->fds[fds[0]] = fds[0];
	ctx->fds[fds[1]] = fds[1];
	return (0);
}

#ifdef STATIC

int	ft_pipe(int *fds)
{
	return (ft_ctxpipe(ft_ctx(), fds));
}
#endif