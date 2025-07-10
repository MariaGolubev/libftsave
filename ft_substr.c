/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:42:50 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:35:05 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_ctxsubstr(t_ctx *ctx, const char *src, unsigned int start,
		size_t len)
{
	size_t	src_len;
	char	*substr;

	if (src == NULL || ctx == NULL)
	{
		errno = EINVAL;
		return (NULL);
	}
	substr = NULL;
	src_len = ft_strlen(src);
	if (start >= src_len)
		return (ft_ctxcalloc(ctx, 1, sizeof(char)));
	if (start + len > src_len)
		len = src_len - start;
	substr = ft_ctxmalloc(ctx, len + 1);
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, &src[start], len);
	substr[len] = '\0';
	return (substr);
}

#ifdef STATIC

char	*ft_substr(const char *src, unsigned int start, size_t len)
{
	return (ft_ctxsubstr(ft_ctx(), src, start, len));
}
#endif
