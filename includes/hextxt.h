/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextxt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:22:25 by plouvel           #+#    #+#             */
/*   Updated: 2021/09/24 15:46:06 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXTXT_H
# define HEXTXT_H

# define SPACE_EACH -1
# define NO_SPACE	-2
# define IN_BLOCK	-3

char	*strtohex(const char *pstr, int mode, unsigned int blk_size);
char	*hextostr(const char *pstr);

#endif
