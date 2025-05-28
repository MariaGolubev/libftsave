/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_open.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 19:53:58 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:35:25 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ctxopen(t_ctx *ctx, const char *pathname, int flags, mode_t mode)
{
	int	fd;

	if (ctx == NULL || pathname == NULL)
		return (-1);
	fd = open(pathname, flags, mode);
	if (fd < 0)
		return (-1);
	if (fd >= MAX_FD)
	{
		close(fd);
		return (-1);
	}
	ctx->fds[fd] = fd;
	return (fd);
}

#ifdef STATIC

int	ft_open(const char *pathname, int flags, mode_t mode)
{
	return (ft_ctxopen(ft_ctx(), pathname, flags, mode));
}
#endif
