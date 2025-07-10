/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:37:06 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:27:12 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

size_t	ft_strlen(const char *s)
{
	const char	*origin;

	origin = s;
	while (*s)
		s++;
	return (s - origin);
}
