/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextxt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:22:05 by plouvel           #+#    #+#             */
/*   Updated: 2021/09/28 19:24:29 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hextxt.h"
#include <stdlib.h>
#include <libgen.h>
#include <stdio.h>

const char	g_usage[] =
	"hextxt: ASCII string <-> hexadecimal conversion\n"
	"usage: ./hextxt [-shm] [input]\n"
	"-s: convert the hexadecimal string into an ASCII string.\n"
	"-h: convert the ASCII string into an hexadecimal string. If no\n"
	"	 mode is specified, the default mode will be SPACE_EACH.\n"
	"-m: output format. To be use when -h option is used.\n\n"
	"		SPACE_EACH	: 01 0f 0a 0b\n"
	"		NO_SPACE	: 010f0a0b\n"
	"		IN_BLOCK	: 010f 0a0b\n\n"
	"IN_BLOCK should be followed by the number of byte per block :\n\n"
	"		./hextxt -h -m IN_BLOCK 2 Hello\n\n"
	"If only the input is provided, it convert the string to hexa-"
	"-decimal using NO_SPACE mode.";

const char	*g_err_table[7] =
{
	0,
	"invalid option, see usage with -h.",
	"missing arguments, see usage with -h.",
	"too much arguments, see usage with -h.",
	"unknown mode, see usage with -h.",
	"invalid block size, can only be >= 1 and <= 16.",
	"couldn't allocate memory."
};

void	print_err(const char *pgrname, const char *msg)
{
	if (pgrname != NULL)
	{
		ft_putstr_fd(pgrname, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
}

void	exit_with_err(const char *pgrname, int err_code)
{
	print_err(pgrname, g_err_table[err_code]);
	exit(err_code);
}

char	*proceed_mode(char *pgrname, char *mode, char *block_size, char *input)
{
	char			*ret;
	int				fmode;
	unsigned int	iblock_size;

	fmode = 0;
	iblock_size = 0;
	if (ft_strcmp(mode, "SPACE_EACH") == 0)
		fmode = SPACE_EACH;
	else if (ft_strcmp(mode, "NO_SPACE") == 0)
		fmode = NO_SPACE;
	else if (ft_strcmp(mode, "IN_BLOCK") == 0)
		fmode = IN_BLOCK;
	else
		exit_with_err(pgrname, UNKN_MODE_ERRC);
	iblock_size = ft_atoi(block_size);
	if (!(iblock_size >= 1 && iblock_size <= 16))
		exit_with_err(pgrname, INVALID_BLOCK_SIZE_ERRC);
	ret = strtohex(input, fmode, iblock_size);
	return (ret);
}

char	*proceed(int argc, char **argv)
{
	char	*ret;

	ret = NULL;
	if (argc == 3)
	{
		if (ft_strcmp(argv[1], "-s") == 0)
			ret = hextostr(argv[2]);
		else if (ft_strcmp(argv[1], "-x") == 0)
			ret = strtohex(argv[2], NO_SPACE, 0);
		else
			exit_with_err(argv[0], INVALID_OPTION_ERRC);
	}
	else if (argc == 6)
	{
		if (ft_strcmp(argv[1], "-x") != 0 || ft_strcmp(argv[2], "-m") != 0)
			exit_with_err(argv[0], INVALID_OPTION_ERRC);
		ret = proceed_mode(argv[0], argv[3], argv[4], argv[5]);
	}
	else if (argc < 3)
		exit_with_err(argv[0], MISS_ARG_ERRC);
	else if (argc > 6)
		exit_with_err(argv[0], TOOM_ARG_ERRC);
	if (!ret)
		exit_with_err(argv[0], ALLOCATION_ERROR_ERRC);
	return (ret);
}

int main(int argc, char **argv)
{
	char	*str;

	argv[0] += 2;
	if (argc == 2 && ft_strcmp(argv[1], "-h") == 0)
		ft_putstr(g_usage);
	else if (argc >= 3 && argc <= 6)
	{
		str = proceed(argc, argv);
		ft_putendl(str);
	}
	else
		exit_with_err(argv[0], INVALID_OPTION_ERRC);
	return (0);
}
