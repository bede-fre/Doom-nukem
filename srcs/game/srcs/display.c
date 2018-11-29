/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/29 17:35:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_fill_pixel(t_img *ptr, int x, int y, int col)
{
	if ((y >= 0 && y < ptr->height) && (x >= 0 && x < ptr->width))
	{
		((char *)(ptr->data))[((x * 4) + (y * ptr->sl))] =
			(char)col;
		((char *)(ptr->data))[((x * 4) + (y * ptr->sl)) + 1] =
			(char)(col >> 8);
		((char *)(ptr->data))[((x * 4) + (y * ptr->sl)) + 2] =
			(char)(col >> 16);
		((char *)(ptr->data))[((x * 4) + (y * ptr->sl)) + 3] =
			(char)(col >> 24);
	}
}

void		ft_print_all(t_all *all)
{
	pthread_t	thread[WINX / THREAD];
	t_all		tmp[WINX / THREAD];
	int			i;
	int			x;

	ft_print_map(&all->info, all->rc.map, all->p);
	all->a = all->p.a + ft_rad(FOV / 2.0);
	all->lens = ft_rad(FOV / 2.0) * all->keys_tab[KEY_H];
	all->i = -THREAD;
	x = 0;
	while ((all->i += THREAD) < WINX)
	{
		ft_cpy_struct(&tmp[x], all);
		pthread_create(&thread[x], NULL, ft_wall_dist, &tmp[x]);
		all->lens -= (double)THREAD * ft_rad(RAY_ANGLE) * all->keys_tab[KEY_H];
		all->a -= (double)THREAD * ft_rad(RAY_ANGLE);
		++x;
	}
	i = -1;
	while (++i < WINX / THREAD)
		pthread_join(thread[i], NULL);
}

int			ft_quit(void)
{
	exit(0);
}

static void	print_commands(void)
{
	ft_putchar('\n');
	ft_putendl("		CONTROL CENTER");
	ft_putchar('\n');
	ft_putendl("Esc		--> Quit");
	ft_putendl("W		--> Move forward");
	ft_putendl("S		--> Move backward");
	ft_putendl("A		--> Move left");
	ft_putendl("D		--> Move right");
	ft_putendl("Q		--> Turn left");
	ft_putendl("E		--> Turn right");
	ft_putendl("Space		--> Jump / Fly");
	ft_putendl("Shift		--> Run");
	ft_putendl("Ctrl		--> Crouch");
	ft_putendl("F		--> Open doors");
	ft_putendl("L		--> Leaks");
	ft_putendl("M		--> Mute");
	ft_putendl("X		--> Active / Desactive fly");
	ft_putendl("H		--> Active / Desactive fish eye");
	ft_putendl("Enter		--> Active / Desactive mouse");
	ft_putendl("Left Clic	--> Print ray info");
	ft_putchar('\n');
}

void		ft_draw(t_all all, char *name)
{
	char	*title;

	print_commands();
	all.prevx = -8000;
	all.prevy = -8000;
	all.start_wall = WINY / 2;
	title = ft_strjoin("doom-nukem - ", name);
	ft_init(&all, title);
	free(title);
	mlx_hook(all.ptr.win, 2, (1L << 0), ft_key_press, &all);
	mlx_hook(all.ptr.win, 3, (1L << 1), ft_key_release, &all);
	mlx_hook(all.ptr.win, 4, (1L << 2), ft_button_press, &all);
	mlx_hook(all.ptr.win, 6, (1L << 6), ft_mouse_motion, &all);
	mlx_hook(all.ptr.win, 17, 0, ft_quit, 0);
	mlx_loop_hook(all.ptr.mlx, ft_movements, &all);
	ft_print_all(&all);
	mlx_loop(all.ptr.mlx);
}
