/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:41:52 by toliver           #+#    #+#             */
/*   Updated: 2018/09/18 17:27:41 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
#define DOOM_H

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "vectors.h"

#define ERROR_PREFIX	"./doom-nukem: "

int						printvec(t_vec a);
void					ft_error(const char *str) __attribute((noreturn));

#endif
