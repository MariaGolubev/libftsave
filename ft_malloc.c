/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:16:47 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:05:55 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ctxmalloc(t_ctx *ctx, size_t size)
{
	void	*ptr;

	if (size == 0 || ctx == NULL)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (ft_ptrlist_prepend(&ctx->ptrs, ptr))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

#ifdef STATIC

void	*ft_malloc(size_t size)
{
	return (ft_ctxmalloc(ft_ctx(), size));
}
#endif
