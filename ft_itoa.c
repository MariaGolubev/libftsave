/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:48:56 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 13:42:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ctxitoa(t_ctx *ctx, int n)
{
	size_t	len;
	char	*str;

	if (n == 0)
		return (ft_ctxstrdup(ctx, "0"));
	if (n == INT_MIN)
		return (ft_ctxstrdup(ctx, "-2147483648"));
	len = numlen(n);
	str = ft_ctxmalloc(ctx, len + 1);
	if (!str)
		return (NULL);
	return (ft_itoa_str(str, n, len));
}

char	*ft_itoa(int n)
{
	return (ft_ctxitoa(ft_ctx_get(), n));
}
