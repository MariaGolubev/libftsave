/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:43:52 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 20:17:45 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctxstrdup(t_ctx *ctx, const char *s1)
{
	char	*copy;
	size_t	size;

	if (!s1)
		return (NULL);
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
