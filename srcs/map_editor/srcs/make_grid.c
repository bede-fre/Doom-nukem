/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 11:35:32 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	make_grid(t_env *env)
{
	t_point p;
	SDL_Color color = {255, 255, 255, 0};

	p.x = -1;
	while (++p.y <= 1080 && (p.x = -1))
		while (++p.x <= 1920)
			if ((p.x + env->grid.gap.x) % env->grid.scale == 0 ||
				(p.y + env->grid.gap.y) % env->grid.scale == 0)
				set_pixel(env->renderer, p.x, p.y, color);
}
