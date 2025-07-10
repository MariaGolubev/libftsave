/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:43:52 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:29:22 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_ctxstrdup(t_ctx *ctx, const char *s1)
{
	char	*copy;
	size_t	size;

	if (!s1 || !ctx)
	{
		errno = EINVAL;
		return (NULL);
	}
	size = ft_strlen(s1) + 1;
	copy = ft_ctxmalloc(ctx, size);
	if (!copy)
		return (NULL);
	return (ft_memcpy(copy, s1, size));
}

#ifdef STATIC

char	*ft_strdup(const char *s1)
{
	return (ft_ctxstrdup(ft_ctx(), s1));
}
#endif
