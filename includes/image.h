/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:25:59 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/09 13:45:21 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# define BYTES_PER_PIXEL	4

typedef struct		s_img
{
	int				bpp;
	int				width;
	int				endian;
	int				height;
	int				linesize;
	void			*ptr;
	char			*data;
}					t_img;

#endif
