#include "wolf3d.h"

void	jump_and_crouch(t_all *all)
{
	static int jump = FALSE;

	if (all->keys_tab[KEY_CTRL] && all->wall_gap1 > (4.0f / 3.0f)
	&& all->wall_gap2 < 4.0f & all->wall_gap1 <= 2.0 && all->wall_gap2 >= 2.0f)
	{
		all->wall_gap1 -= (2.0 - (4.0f / 3.0f)) / TRANS_F;
		all->wall_gap2 += (4.0f - 2.0f) / TRANS_F;
	}
	else if (!all->keys_tab[KEY_CTRL] && all->wall_gap1 < 2.0f)
	{
		all->wall_gap1 += (2.0 - (4.0f / 3.0f)) / TRANS_F;
		all->wall_gap2 -= (4.0f - 2.0f) / TRANS_F;
	}
	else if (jump)
	{
		all->wall_gap1 += 0.2f;
		all->wall_gap2 -= 0.067f;
		jump = (all->wall_gap1 >= 4.0f && all->wall_gap2 <= 1.33f) ? FALSE : TRUE;
	}
	else if (all->keys_tab[KEY_SPACEBAR] && all->wall_gap1 == 2.0f && !jump)
		jump = TRUE;
	else if (all->wall_gap1 > 2.0f && all->wall_gap2 < 2.0f && !jump)
	{
		all->wall_gap1 -= 0.2f;
		all->wall_gap2 += 0.067f;
	}
}

void	open_door(t_all *all)
{
	all->a = all->p.a - ft_rad(((WINY) - (WINX / 2) - 1) * RAY_ANGLE);
	ft_fp_hori(&all->rc.ray_h, &all->p, all->rc.map, all->a);
	ft_fp_vert(&all->rc.ray_v, &all->p, all->rc.map, all->a);
	if (all->rc.ray_h.dist != all->rc.ray_h.dist ||
		all->rc.ray_v.dist != all->rc.ray_v.dist)
		all->rc.ray = (all->rc.ray_h.dist != all->rc.ray_h.dist) ?
		all->rc.ray_v : all->rc.ray_h;
	else
		all->rc.ray = (all->rc.ray_h.dist <= all->rc.ray_v.dist) ?
		all->rc.ray_h : all->rc.ray_v;
	printf("all->rc.ray.x: %f\n", all->rc.ray.x);
	printf("all->rc.ray.y: %f\n", all->rc.ray.y);

	printf("Lettre: %c\n", all->rc.map[to_map(all->rc.ray_v.y)][to_map(all->rc.ray_v.x)]);
	printf("Y: %d  X: %d\n", to_map(all->rc.ray_v.y), to_map(all->rc.ray_v.x));

	printf("all->a: %f\n", all->a);

	// printf("all->rc.ray.dx: %f\n", all->rc.ray.dx);
	// printf("all->rc.ray.fx: %f\n", all->rc.ray.fx);
	// printf("all->rc.ray.xa: %f\n", all->rc.ray.xa);
	
	// printf("all->rc.ray_h.x: %f\n", all->rc.ray_h.x);
	// printf("all->rc.ray_h.dx: %f\n", all->rc.ray_h.dx);
	// printf("all->rc.ray_h.fx: %f\n", all->rc.ray_h.fx);
	// printf("all->rc.ray_h.xa: %f\n", all->rc.ray_h.xa);

	// printf("all->rc.ray_v.x: %f\n", all->rc.ray_v.x);
	// printf("all->rc.ray_v.dx: %f\n", all->rc.ray_v.dx);
	// printf("all->rc.ray_v.fx: %f\n", all->rc.ray_v.fx);
	// printf("all->rc.ray_v.xa: %f\n", all->rc.ray_v.xa);

	// printf("all->prevx: %f\n", all->x);

	if (all->rc.map[to_map(all->rc.ray_v.y)][to_map(all->rc.ray_v.x)] == T_DOOR_C) {
			ft_putstr("door open\n");
	}
}