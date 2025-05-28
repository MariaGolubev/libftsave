/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:18:04 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 11:20:43 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ctxcalloc(t_ctx *ctx, size_t m, size_t n)
{
	void	*buff;

	if (n && m > __SIZE_MAX__ / n)
		return (NULL);
	n = n * m;
	buff = ft_ctxmalloc(ctx, n);
	if (buff == NULL)
		return (NULL);
	ft_bzero(buff, n);
	return (buff);
}

void	*ft_calloc(size_t count, size_t size)
{
	return (ft_ctxcalloc(ft_ctx_get(), count, size));
}
