/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:25:59 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/24 17:04:17 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct		s_img
{
	void			*ptr;
	char			*data;

	int				bpp;
	int				linesize;
	int				endian;
	int				width;
	int				height;

}					t_img;

# define BYTES_PER_PIXEL	4

#endif