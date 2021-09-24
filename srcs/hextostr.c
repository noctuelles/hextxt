/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:32:20 by plouvel           #+#    #+#             */
/*   Updated: 2021/09/24 15:48:48 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static bool	valid_hex(unsigned char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
			|| (c >= 'A' && c <= 'F'))
		return (true);
	return (false);
}

static size_t	check_str(const char *pstr)
{
	size_t	hexnbr;
	size_t	limit;

	hexnbr = 0;
	limit = 2147483647;
	while (*pstr != '\0' && limit--)
	{
		if (!valid_hex(*pstr))
		{
			if (!ft_isspace(*pstr))
				return (0);
		}
		else
			hexnbr++;
		pstr++;
	}
	return (hexnbr);
}

static unsigned int	htoi(char c)
{
	if (c <= '9')
		return (c - '0');
	return (c - 'a' + 10);
}

static unsigned char	htoc(const char **pstr)
{
	unsigned char	c;

	c = htoi((*pstr)[0]);
	if (valid_hex((*pstr)[1]))
	{
		c = c * 16 + htoi((*pstr)[1]);
		(*pstr)++;
	}
	if (!ft_isascii(c))
		return ('.');
	return (c);
}

char	*hextostr(const char *pstr)
{
	char	*conv;
	size_t	size_conv;
	size_t	i;

	size_conv = check_str(pstr);
	i = 0;
	if(!size_conv)
		return (NULL);
	conv = (char *) malloc((size_conv + 1) * sizeof(char));
	if (!conv)
		return (NULL);
	while (*pstr != '\0')
	{
		if (valid_hex(*pstr))
			conv[i++] = htoc(&pstr);
		pstr++;
	}
	conv[i] = '\0';
	return (conv);
}
