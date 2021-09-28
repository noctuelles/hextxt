/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextxt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:22:25 by plouvel           #+#    #+#             */
/*   Updated: 2021/09/28 20:01:59 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXTXT_H
# define HEXTXT_H

# define SPACE_EACH 1
# define NO_SPACE	2
# define IN_BLOCK	3

# define HEX_TO_STR 1
# define STR_TO_HEX 2

# define INVALID_OPTION_ERRC 0
# define MISS_ARG_ERRC 1
# define TOOM_ARG_ERRC 2
# define UNKN_MODE_ERRC 3
# define INVALID_BLOCK_SIZE_ERRC 4
# define ALLOCATION_ERROR_ERRC 5 
# define INVALID_INPUT_HEX 6
# define INVALID_INPUT_STR 7


char	*strtohex(const char *pstr, int mode, unsigned int blk_size);
char	*hextostr(const char *pstr);
void	exit_with_err(int err_code);

#endif
