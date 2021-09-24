/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:50:30 by plouvel           #+#    #+#             */
/*   Updated: 2021/09/24 15:24:23 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define SPACE_EACH -2
# define NO_SPACE	-3
# define IN_BLOCK	-4

#include "libft.h"
#include <stdlib.h>

size_t	check_str(const char *pstr, int mode, unsigned int blk_size)
{
	size_t	size;

	size = 0;
	while (*pstr != '\0')
	{
		if (!ft_isascii(*pstr))
			return (0);
		size++;
		pstr++;
	}
	size *= 2;
	if (mode == SPACE_EACH)
		size = size * 2 - 1;
	else if (mode == IN_BLOCK)
		size += size / blk_size;
	return (size);
}

char	itoch(unsigned int i)
{
	if (i > 9)
		return ('a' + (i - 10));
	return ('0' + i);
}

char	*strtohex(const char *pstr, int mode, unsigned int blk_size)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	char_c;

	size = check_str(pstr, mode, blk_size);
	if (!size)
		return (NULL);
	str = (char *) malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	char_c = 0;
	while (*pstr != '\0')
	{
		str[i++] = itoch(*pstr / 16);
		str[i++] = itoch(*pstr % 16);
		char_c += 2;
		if (mode == SPACE_EACH || (mode == IN_BLOCK && char_c % (blk_size * 2) == 0))
			str[i++] = ' ';
		pstr++;
	}
	str[i] = '\0';
	return (str);
}
