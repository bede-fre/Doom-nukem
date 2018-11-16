#include "wolf3d.h"

void	jump_and_crouch(t_all *all)
{
	static int jump = FALSE;

	if (all->keys_tab[KEY_CTRL] && all->wall_gap >= 0.0 && all->wall_gap < 1.0)
		all->wall_gap += 0.1;
	else if (!all->keys_tab[KEY_CTRL] && all->wall_gap > 0.0)
	{
		all->wall_gap -= 0.1;
		if (all->wall_gap <= 0.0)
			all->wall_gap = 0.0;
	}
	else if (jump)
	{
		all->wall_gap -= 0.2;
		jump = (all->wall_gap <= -1.0) ? FALSE : TRUE;
	}
	else if (all->keys_tab[KEY_SPACEBAR] && all->wall_gap == 0.0)
		jump = TRUE;
	else if (all->wall_gap < 0.0)
	{
		all->wall_gap += 0.1;
		if (all->wall_gap >= 0.0)
			all->wall_gap = 0.0;
	}
}
