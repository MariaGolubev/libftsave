/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:27:10 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 12:27:16 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*fn)(unsigned int, char *))
{
	size_t	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		fn((unsigned int)pos, &str[pos]);
		pos++;
	}
}
