/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:38:44 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 12:40:42 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	f_start(const char *src, const char *set)
{
	size_t	start;

	start = 0;
	while (src[start] && ft_strchr(set, src[start]))
		start++;
	return (start);
}

static size_t	f_end(size_t start, const char *src, const char *set)
{
	size_t	end;

	end = start;
	while (src[end])
		end++;
	while (end > start && ft_strchr(set, src[end - 1]))
		end--;
	return (end);
}

char	*ft_ctxstrtrim(t_ctx *ctx, const char *src, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result;

	if (!src || !set)
		return (NULL);
	start = f_start(src, set);
	end = f_end(start, src, set);
	len = end - start;
	result = ft_ctxmalloc(ctx, len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, src + start, len);
	result[len] = '\0';
	return (result);
}

char	*ft_strtrim(const char *src, const char *set)
{
	return (ft_ctxstrtrim(ft_ctx_get(), src, set));
}
