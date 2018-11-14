#include "wolf3d.h"

void	jump_and_crouch(t_all *all)
{
	static int jump = FALSE;

	if (all->keys_tab[KEY_CTRL] && all->wall_gap1 > (4.0f / 3.0f)
			&& all->wall_gap2 < 4.0f
					&& all->wall_gap1 <= 2.0 && all->wall_gap2 >= 2.0f) {
		all->wall_gap1 -= (2.0 - (4.0f / 3.0f)) / TRANS_F;
		all->wall_gap2 += (4.0f - 2.0f) / TRANS_F;
	} else if (!all->keys_tab[KEY_CTRL] && all->wall_gap1 < 2.0f
			&& all->wall_gap2 > 2.0f) {
		all->wall_gap1 += (2.0 - (4.0f / 3.0f)) / TRANS_F;
		all->wall_gap2 -= (4.0f - 2.0f) / TRANS_F;
	}
	else if (jump) {
		all->wall_gap1 += 0.2f;
		all->wall_gap2 -= 0.067f;
		if (all->wall_gap1 >= 4.0f && all->wall_gap2 <= 1.33f)
			jump = FALSE;
	}
	else if (all->keys_tab[KEY_SPACEBAR] && all->wall_gap1 == 2.0f
			&& all->wall_gap2 == 2.0f && !jump)
		jump = TRUE;
	else if (all->wall_gap1 > 2.0f && all->wall_gap2 < 2.0f && !jump) {
		all->wall_gap1 -= 0.2f;
		all->wall_gap2 += 0.067f;
	}
}