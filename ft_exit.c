/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:57:25 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:14:36 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ctxexit(t_ctx *ctx, int status)
{
	ft_ctxdestroy(ctx);
	exit(status);
}

#ifdef STATIC

void	ft_exit(int status)
{
	ft_ctxexit(ft_ctx(), status);
}
#endif
