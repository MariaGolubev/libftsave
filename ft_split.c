/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:18:13 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:16:54 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

static char	**free_array(t_ctx *ctx, char **arr)
{
	size_t	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		ft_ctxfree(ctx, arr[i]);
		i++;
	}
	ft_ctxfree(ctx, arr);
	return (NULL);
}

static char	*next_substring(t_ctx *ctx, const char **src, char c)
{
	const char	*start;
	size_t		len;
	char		*substring;

	start = NULL;
	len = 0;
	while (**src && **src == c)
		(*src)++;
	start = *src;
	while (**src && **src != c)
	{
		len++;
		(*src)++;
	}
	substring = (char *)ft_ctxmalloc(ctx, (len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	substring[len] = '\0';
	return (ft_memcpy(substring, start, len));
}

static size_t	count_substring(const char *src, char c)
{
	size_t	count;

	count = 0;
	while (*src && *src == c)
		src++;
	while (*src)
	{
		if (*src != c)
		{
			count++;
			while (*src && *src != c)
				src++;
		}
		else
			src++;
	}
	return (count);
}

char	**ft_ctxsplit(t_ctx *ctx, const char *s, char c)
{
	char	**arr;
	size_t	count;
	size_t	i;

	if (s == NULL || ctx == NULL)
	{
		errno = EINVAL;
		return (NULL);
	}
	count = count_substring(s, c);
	arr = ft_ctxcalloc(ctx, count + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		arr[i] = next_substring(ctx, &s, c);
		if (arr[i] == NULL)
			return (free_array(ctx, arr));
		i++;
	}
	return (arr);
}

#ifdef STATIC

char	**ft_split(const char *s, char c)
{
	return (ft_ctxsplit(ft_ctx(), s, c));
}
#endif
