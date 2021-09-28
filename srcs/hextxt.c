/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextxt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:22:05 by plouvel           #+#    #+#             */
/*   Updated: 2021/09/28 20:19:11 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hextxt.h"
#include <stdlib.h>
#include <libgen.h>
#include <stdio.h>

static const char	g_usage[620] =
	"hextxt: ASCII string <-> hexadecimal conversion\n"
	"usage: ./hextxt [-sx] [-m] [input]\n"
	"-s : convert the hexadecimal string into an ASCII string.\n"
	"-x : convert the ASCII string into an hexadecimal. If no mode\n"
	"     is specified, the default mode will be SPACE_EACH.\n"
	"-m : output format. To be use only when -h option is used.\n\n"
	"	SPACE_EACH	: 01 0f 0a 0b\n"
	"	NO_SPACE	: 010f0a0b\n"
	"	IN_BLOCK	: 010f 0a0b (with 2 bytes per block)\n\n"
	"IN_BLOCK should be followed by the number of byte per block :\n\n"
	"	./hextxt -h -m IN_BLOCK 2 Hello\n\n"
	"	4865 6c6c 6f\n\n"
	"If only the input is provided, it converts the string to hex-\n"
	"-adecimal using NO_SPACE mode.\n";

static const char	*g_err_table[8] =
{
	"invalid option, see usage with -h.",
	"missing arguments, see usage with -h.",
	"too much arguments, see usage with -h.",
	"unknown mode, see usage with -h.",
	"invalid block size, can only be >= 1 and <= 16.",
	"couldn't allocate memory.",
	"invalid input, the program only accept valid hexadecimal character.",
	"invalid input, the program can only accept valid ASCII character."
};

static char	*g_pgrname = NULL;

static void	print_err(const char *msg)
{
	ft_putstr_fd(g_pgrname, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

void	exit_with_err(int err_code)
{
	print_err(g_err_table[err_code]);
	exit(err_code);
}

char	*proceed_mode(char *mode, char *block_size, char *input)
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
		exit_with_err(UNKN_MODE_ERRC);
	iblock_size = ft_atoi(block_size);
	if (!(iblock_size >= 1 && iblock_size <= 16))
		exit_with_err(INVALID_BLOCK_SIZE_ERRC);
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
			exit_with_err(INVALID_OPTION_ERRC);
	}
	else if (argc == 6)
	{
		if (ft_strcmp(argv[1], "-x") != 0 || ft_strcmp(argv[2], "-m") != 0)
			exit_with_err(INVALID_OPTION_ERRC);
		ret = proceed_mode(argv[3], argv[4], argv[5]);
	}
	return (ret);
}

int main(int argc, char **argv)
{
	char	*str;

	g_pgrname = argv[0] += 2;
	str = NULL;
	if (argc == 2)
	{
		if(ft_strcmp(argv[1], "-h") == 0)
			ft_putstr(g_usage);
		else
			exit_with_err(INVALID_OPTION_ERRC);
	}
	else if (argc == 3 || argc == 6)
	{
		str = proceed(argc, argv);
		ft_putendl(str);
	}
	else if (argc < 3 || (argc > 3 && argc < 6))
		exit_with_err(MISS_ARG_ERRC);
	else if (argc > 6)
		exit_with_err(TOOM_ARG_ERRC);
	free(str);
	return (0);
}
