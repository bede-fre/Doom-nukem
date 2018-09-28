/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/28 17:30:03 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int							ft_printrays(t_doom *env, t_img *img)
{
	float					increment;
	t_vec					raydir;
	int						i;

	increment = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(env->player.rot, -(FOV / 2));
	i = 0;
	while (i < WIN_WIDTH)
	{
		ft_putline(ft_vecscale(env->player.pos, 10), ft_vecadd(ft_vecscale(env->player.pos, 10), ft_vecscale(raydir, 10)), img, 0xaaff00);
//		ft_putline(ft_vecscale(env->player.pos, 10), ft_vecscale(ft_vecadd(env->player.pos, raydir), 20), &env->img, 0xaaff00);
		raydir = ft_vecrotz(raydir, increment);
		i++;
	}
	return (1);
}

int							ft_printplayer(t_doom *env, t_img *img)
{
	t_vec					playerpos;

	playerpos = ft_vecscale(env->player.pos, 10);
	px_to_img(img, playerpos.x, playerpos.y, 0xffff00);
	ft_printrays(env, img);
	return (1);
}

int							ft_printmap(t_doom *env, t_img *img)
{
	merge_images(img, &env->map, 0, 0);
	return (1);
}

static void					ft_make_minimap(t_doom *env, t_img *img)
{
	t_vec	vect;
	int	x;
	int	y;
	int	i;
	int	j;

	i = (int)(env->player.pos.x * 10.0 - (float)MAP_WIDTH / 2.0);
	j = (int)(env->player.pos.y * 10.0 - (float)MAP_HEIGHT / 2.0);
	x = -1;
	while (++x < MAP_WIDTH)
	{
		y = -1;
		while (++y < MAP_HEIGHT)
		{
			vect = ft_vecdef((float)x - (float)MAP_WIDTH / 2.0, (float)y - (float)MAP_HEIGHT / 2.0, 0);
			vect = ft_vecrotz(vect, env->angle);
			vect.x += env->player.pos.x * 10.0;
			vect.y += env->player.pos.y * 10.0;
			if (vect.x < 0 || vect.y < 0 || vect.x >= WIN_WIDTH || vect.y >= WIN_HEIGHT)
				px_to_img(&env->minimap, x, y, 0);
			else
			{
				env->minimap.data[x * 4 + y * 4 * MAP_WIDTH] = img->data[(int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH];
				env->minimap.data[(x * 4 + y * 4 * MAP_WIDTH) + 1] = img->data[((int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH) + 1];
				env->minimap.data[(x * 4 + y * 4 * MAP_WIDTH) + 2] = img->data[((int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH) + 2];
				env->minimap.data[(x * 4 + y * 4 * MAP_WIDTH) + 3] = img->data[((int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH) + 3];
			}
			if (x == 0 || y == 0 || x == MAP_WIDTH - 1 || y == MAP_HEIGHT - 1)
				px_to_img(&env->minimap, x, y, 0xFFFFFF);
		}
	}
}

float						crossproduct2d(t_vec a, t_vec b)
{
	return (a.x * b.y - a.y * b.x);
}

float						rayintersect(t_vec rayorigin, t_vec raydir, t_line wall)
{
	t_vec					v1;
	t_vec					v2;
	t_vec					v3;
	float					dotproduct;
	float					t1;
	float					t2;

	v1 = ft_vecsub(rayorigin, wall.a);
	v1.z = 0;
	v2 = ft_vecsub(wall.b, wall.a);
	v2.z = 0;
	v3 = ft_vecdef(-raydir.y, raydir.x, 0);
	v3.z = 0;
	dotproduct = ft_dot_product(v2, v3);
	if (fabs(dotproduct) == 0)
		return (INFINITY);
	t1 = crossproduct2d(v2, v1) / dotproduct;
	t2 = (v1.x * v3.x + v1.y * v3.y) / dotproduct;
	if (t1 >= 0.0 && (t2 >= 0.0 && t2 <= 1.0))
		return (t1);
	return (INFINITY);
}

float						ft_rayintersect(t_vec pos, t_vec dir, t_zone **zones, t_doom *env)
{
	float					intersect;
	float					tmpintersect;
	t_line					wall;
	int						i;

	i = 0;
	intersect = INFINITY;
	while (zones[0]->walls[i]) // a changer quand on aura plus de zones (ne tester que la zone du player)
	{
		wall.a = zones[0]->walls[i]->origin;
		wall.b = (zones[0]->walls[i + 1]) ? zones[0]->walls[i + 1]->origin : zones[0]->walls[0]->origin;
		tmpintersect = rayintersect(pos, dir, wall);
		if (tmpintersect != INFINITY)
		{
	//		printf("intersect = %f\n", tmpintersect);
	//		printf("x = %f, y = %f\n", ft_vecadd(pos, ft_vecscale(ft_vecdef(cosf(env->player.rotangle.z), sinf(env->player.rotangle.z), 0), tmpintersect)).x, ft_vecadd(pos, ft_vecscale(ft_vecdef(cosf(env->player.rotangle.z), sinf(env->player.rotangle.z), 0), tmpintersect)).y);
			if (intersect != INFINITY || tmpintersect < intersect)
				intersect = tmpintersect;
		}
		i++;	
	}
	return (intersect);
}

void						ft_make_view(t_doom *env, t_img *img)
{
	float					increment;
	t_vec					raydir;
	int						i;
	float					intersect;
	float					angle;
	float					testcos;

	increment = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(env->player.rot, -(FOV / 2));
	i = 0;
	bzero(img->data, img->width * img->height * 4);
	angle = -(FOV / 2);
	while (i < WIN_WIDTH)
	{
		intersect = ft_rayintersect(env->player.pos, raydir, env->zones, env);
		if (intersect != INFINITY)
		{
	//		ft_putline(ft_vecscale(env->player.pos, 10), ft_vecscale(ft_vecadd(env->player.pos, ft_vecscale(raydir, intersect)), 10), img, 0xffff00); 
			testcos = cosf(ft_degtorad(fabsf(angle)));
			intersect = intersect * testcos / 20;
			if (intersect != 0)
			{	
				ft_putline(ft_vecdef(i, (img->height / 2) * intersect, 0), ft_vecdef(i,img->height - ((img->height / 2) * intersect), 0), img, 0xffffff);
			}
		}
		angle += increment;
		raydir = ft_vecrotz(raydir, increment);
		i++;
	}
//	printf("test = %d, should be %d\n", test, WIN_WIDTH);
}

void						render(t_doom *doom)
{
//	mlx_put_image_to_window(doom->mlx, doom->window, doom->minimap.ptr, 300, 300);
	bzero(doom->img.data, doom->img.width * doom->img.height * 4);
	playermove(doom);
	ft_make_minimap(doom, &doom->img);
	ft_make_view(doom, &doom->img);
	ft_printmap(doom, &doom->img);
	ft_printplayer(doom, &doom->img);
	mlx_put_image_to_window(doom->mlx ,doom->window, doom->img.ptr, 0, 0);
	//mlx_put_image_to_window(doom->mlx, doom->window, doom->minimap.ptr, 300, 300);
//	mlx_put_image_to_window(doom->mlx, doom->window, doom->view.ptr, 300, 300);
	//	printf("Render\n");
}
