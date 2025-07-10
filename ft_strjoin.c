/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:31:15 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:29:16 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_ctxstrjoin(t_ctx *ctx, const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || !s2 || !ctx)
	{
		errno = EINVAL;
		return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = ft_ctxmalloc(ctx, len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2 + 1);
	return (result);
}

#ifdef STATIC

char	*ft_strjoin(const char *s1, const char *s2)
{
	return (ft_ctxstrjoin(ft_ctx(), s1, s2));
}
#endif
