/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:36:01 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:30:42 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_ctxstrmapi(t_ctx *ctx, const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	if (!s || !f || !ctx)
	{
		errno = EINVAL;
		return (NULL);
	}
	len = ft_strlen(s);
	result = ft_ctxmalloc(ctx, len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

#ifdef STATIC

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	return (ft_ctxstrmapi(ft_ctx(), s, f));
}
#endif
