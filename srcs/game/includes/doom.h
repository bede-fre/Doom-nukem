/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:51:58 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 12:06:41 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "libft.h"
# include "libvect.h"
# include "mlx.h"
# include "SDL.h"
# include "SDL_mixer.h"
# include <math.h>
# include <limits.h>
# include <pthread.h>

# define WINX				960
# define WINY				540
# define MAPX				32
# define MAPY				MAPX
# define INFOX				(WINY / 4)
# define INFOY				(WINY / 4)
# define BARX				(int)((double)WINX / 1.4)
# define BARY				(WINY - 45)
# define BARW				250
# define BARH				15
# define F_TEXT				"srcs/game/textures/"
# define F_SPRITE			"srcs/game/sprites/"
# define F_IMAGE			"srcs/game/images/"
# define F_MUSIC			"srcs/game/musics/"
# define F_SOUNDS			"srcs/game/sounds/"
# define TEXT_NORTH			F_TEXT"wood1.xpm"
# define TEXT_SOUTH			F_TEXT"stone1.xpm"
# define TEXT_EAST			F_TEXT"metal1.xpm"
# define TEXT_WEST			F_TEXT"ice1.xpm"
# define TEXT_DOOR			F_TEXT"door.xpm"
# define TEXT_DOOR_R		F_TEXT"door_reverse.xpm"
# define TEXT_NETHER		F_TEXT"nether.xpm"
# define SPR_BARREL			F_SPRITE"barrel.xpm"
# define SPR_ENNEMY			F_SPRITE"Ennemy.xpm"
# define SPR_LIGHTNING		F_SPRITE"lightning.xpm"
# define SPR_JETPACK		F_SPRITE"jetpack.xpm"
# define SPR_JETPACK_BIG	F_SPRITE"jetpack_big.xpm"
# define SPR_WALK			F_SPRITE"Walk_Sprite2.xpm"
# define SPR_JUMP			F_SPRITE"Jump_Sprite2.xpm"
# define SPR_CROUCH			F_SPRITE"Crouch_Sprite2.xpm"
# define SPR_IDLE			F_SPRITE"Idle_Sprite2.xpm"
# define SPR_RUN			F_SPRITE"Run_Sprite2.xpm"
# define GIRL_FACE			F_SPRITE"deathknight_face.xpm"
# define GIRL_LEFT			F_SPRITE"deathknight_left.xpm"
# define GIRL_RIGHT			F_SPRITE"deathknight_right.xpm"
# define GIRL_BACK			F_SPRITE"deathknight_back.xpm"
# define MUTE_IMG			F_IMAGE"soundmute.xpm"
# define END_IMG			F_IMAGE"End_img.xpm"
# define M_WOAH				F_MUSIC"WOAH.wav"
# define S_OPENDOOR			F_SOUNDS"door_open.wav"
# define S_CLOSEDOOR		F_SOUNDS"door_close.wav"
# define S_TELEPORT			F_SOUNDS"teleport.wav"
# define M_WIN				F_MUSIC"win.wav"
# define BLOCK_SIZE			64.0
# define CAM_HEIGHT			BLOCK_SIZE / 2.0
# define FOV				60.0
# define RAY_ANGLE			FOV / (double)WINX
# define START				's'
# define END				'e'
# define FLOOR				' '
# define TP_S				'1'
# define TP_E				'2'
# define BARREL				'3'
# define ENNEMY				'4'
# define LIGHTNING			'5'
# define JETPACK			'6'
# define GIRL				'7'
# define WOOD				'A'
# define WOOD_S				'a'
# define METAL				'B'
# define METAL_S			'b'
# define STONE				'C'
# define STONE_S			'c'
# define ICE				'D'
# define ICE_S				'd'
# define DOOR_C				'-'
# define DOOR_I				'i'
# define DOOR_R				'r'
# define DOOR_O				'_'
# define ALPHA				0xFF000000
# define GREEN_A			0x5517EE01
# define ORANGE_A			0x55FF710F
# define BLACK				0
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN				0xFF00
# define BLUE				0x0061ff
# define LIGHT_BLUE			ALPHA
# define LIGHT_GREEN		0xAAFFAA
# define GREY				0x888888
# define GREY_A				0x44888888
# define YELLOW				0xFFFF00
# define PURPLE				0x642EFE
# define TOP				0x585858
# define BOTTOM				0x323232
# define N_W				0x940602
# define S_W				0x50468C
# define E_W				0x769600
# define W_W				0xD45E3A
# define NORTH				M_PI / 2.0
# define SOUTH				3.0 * M_PI / 2.0
# define WEST				M_PI
# define EAST				0.0
# define EAST2				2.0 * M_PI
# define HIT_BOX			5.0
# define VIEW_DIST			20.0
# define TRANS_F			10
# define DOOR_SPEED			0.0007
# define ZOOM				(((double)MAPX * BLOCK_SIZE / 4.0) / (double)INFOX)
# define P_SIZE				2.5
# define LITTLE				0.00000000000012
# define TRUE				1
# define FALSE				0
# define NB_THREAD			4
# define THREAD				(WINX / NB_THREAD)
# define STAMINA_MAX		200.0
# define JUMP_STA			(int)(STAMINA_MAX / 5.0)

# ifdef __linux__
#  define MOVE_SPEED		2.0
#  define RUN_SPEED			3.0
#  define JUMP_SPEED		0.1
#  define CROUCH_SPEED		1.0
#  define ROT_SPEED			1.0
#  define ESC				65307
#  define KEY_A				97
#  define KEY_D				100
#  define KEY_W				119
#  define KEY_S				115
#  define KEY_H				104
#  define KEY_Q				113
#  define KEY_E				101
#  define KEY_F				102
#  define KEY_L				37
#  define KEY_X				7
#  define KEY_SPACEBAR		32
#  define KEY_CTRL			256
#  define KEY_ENTER			36
#  define KEY_SHIFT			65505
#  define KEYS_TAB_SIZE		65600
# else
#  define MOVE_SPEED		2.0
#  define RUN_SPEED			5.0
#  define JUMP_SPEED		0.1
#  define CROUCH_SPEED		1.0
#  define ROT_SPEED			2.0
#  define ESC				53
#  define KEY_A				0
#  define KEY_D				2
#  define KEY_W				13
#  define KEY_S				1
#  define KEY_H				4
#  define KEY_Q				12
#  define KEY_E				14
#  define KEY_F				3
#  define KEY_L				37
#  define KEY_M				46
#  define KEY_X				7
#  define KEY_SPACEBAR		49
#  define KEY_CTRL			256
#  define KEY_ENTER			36
#  define KEY_SHIFT			257
#  define KEYS_TAB_SIZE		280
# endif

typedef struct		s_fourtout
{
	double			i;
	t_mat3			tp;
	t_point			p;
	t_point			save;
	t_mat3			v_inter;
	t_mat3			v_sprite;
}					t_fourtout;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_fcoord
{
	double			x;
	double			y;
}					t_fcoord;

typedef struct		s_player
{
	int				ray_infos;
	double			x;
	double			y;
	double			a;
}					t_player;

typedef struct		s_parse
{
	char			*buff;
	char			fd;
	short			i;
}					t_parse;

typedef struct		s_ray
{
	double			dist;
	int				hit;
	double			fx;
	double			fy;
	double			xa;
	double			ya;
	double			dx;
	double			dy;
	double			x;
	double			y;
	t_mat3			sprite;
	t_mat3			inter;
	double			sprite_dist;
	int				test;
}					t_ray;

typedef struct		s_raycast
{
	char			map[MAPY][MAPX];
	t_ray			ray_h;
	t_ray			ray_v;
	t_ray			ray;
}					t_raycast;

typedef struct		s_img
{
	int				endian;
	char			*data;
	void			*img;
	int				bpp;
	int				sl;
	int				width;
	int				height;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			info;
	t_img			fp;
}					t_mlx;

typedef struct		s_algo_brez
{
	int				cumul;
	int				cpta;
	int				cptb;
	int				da;
	int				db;
	int				i;
	int				a;
	int				b;
}					t_algo_brez;

typedef struct		s_sprites
{
	t_img			barrel;
	t_img			ennemy;
	t_img			lightning;
	t_img			jetpack;
	t_img			girl_face;
	t_img			girl_left;
	t_img			girl_right;
	t_img			girl_back;
}					t_sprites;

typedef struct		s_textures
{
	int				height;
	int				width;
	t_img			img_w;
	t_img			img_e;
	t_img			img_n;
	t_img			img_s;
	t_img			img_d;
	t_img			img_dr;
	t_img			nether;
}					t_textures;

typedef struct		s_musics
{
	Mix_Music		*musics;
	Mix_Music		*win;
}					t_musics;

typedef struct		s_sounds
{
	Mix_Chunk		*opendoor;
	Mix_Chunk		*closedoor;
	Mix_Chunk		*teleport;
}					t_sounds;

typedef struct		s_hud
{
	t_img			s_jump;
	t_img			s_run;
	t_img			s_idle;
	t_img			s_walk;
	t_img			s_crouch;
	t_img			stamina_bar;
	t_img			mute;
	t_img			jetpack;
}					t_hud;

typedef struct		s_all
{
	int				keys_tab[KEYS_TAB_SIZE];
	t_fourtout		var;
	t_musics		musics;
	t_sounds		sounds;
	t_textures		textures;
	t_sprites		sprites;
	t_hud			hud;
	t_img			info;
	t_img			map;
	t_img			end_img;
	t_mlx			ptr;
	t_img			fp;
	t_raycast		rc;
	t_player		p;
	double			a;
	int				i;
	double			lens;
	int				x;
	int				prevx;
	int				prevy;
	int				start_wall;
	int				skip;
	double			wall_gap;
	double			speed;
	int				s_jump;
	int				jump;
	int				s_idle;
	int				stamina;
	int				end;
	int				mute;
	int				jetpack;
}					t_all;

void				*ft_wall_dist(void *ptr);
void				ft_print_ray_infos(t_all *all);
void				ft_algo(t_img *ptr, t_point p1, t_point p2, int col);
int					ft_button_press(int key, int x, int y, t_all *all);
void				ft_init_player(char map[MAPY][MAPX], t_player *p);
void				ft_read_file(char *name, char (*map)[MAPY][MAPX]);
void				ft_init_keys_tab(int (*keys_tab)[KEYS_TAB_SIZE]);
void				ft_fill_pixel(t_img *ptr, int x, int y, int col);
void				ft_print_on_screen(t_all *all, int x, double a);
void				ft_print_map(t_img *ptr, char map[MAPY][MAPX], t_player p);
void				ft_perso(t_img *img, t_player p);
void				ft_init(t_all *all, char *title);
int					ft_key_release(int key, t_all *all);
void				ft_free_map(char map[MAPY][MAPX]);
int					ft_key_press(int key, t_all *all);
void				ft_draw(t_all all, char *name);
void				ft_print_all(t_all *all);
int					ft_movements(t_all *all);
int					ft_quit(void);
void				ft_cpy_struct(t_all *tmp, t_all *all);
int					ft_mouse_motion(int x, int y, t_all *all);
int					to_map(double x);
int					to_win(int x);
int					is_wall(char wall);
int					is_door(char map[MAPY][MAPX], t_ray *ray);
int					is_displayable(char c);
void				jump_and_crouch(t_all *all);
void				ft_fp_hori(t_ray *ray, t_player p, char map[MAPY][MAPX],
						double a);
void				ft_fp_vert(t_ray *ray, t_player p, char map[MAPY][MAPX],
						double a);
int					ft_wall_height_on_screen(double dist);
void				display_map(char map[MAPY][MAPX]);
void				door_open(t_all *all);
float				door_timer(float add, int x, int y, char map[MAPY][MAPX]);
void				door_update_status(t_all *all);
void				door_update(float timer[MAPY][MAPX], char map[MAPY][MAPX]);
void				door_auto(char map[MAPY][MAPX], t_player p, t_point	i);
void				ft_init_sdl(t_all *all);
void				init_sounds(t_all *all);
int					is_movement(int keys_tab[KEYS_TAB_SIZE]);
void				init_image(t_mlx ptr, t_img *img, int x, int y);
void				print_stamina_bar(t_img *img, int stamina, int col);
void				stamina_control(t_all *all);
void				refresh_events(t_all *all);
void				ft_moving(t_all *all, double dir);
void				ft_strafing(t_all *all, double dir);
void				scale_img(t_img *dst, t_img *src);
void				it_is_the_end(t_all *all);
void				mute_sound(t_all *all);
void				init_xpm(t_mlx ptr, t_img *img, char *path);
int					is_sprite(char c);
int					ft_find_color(t_all *all, double cpt, int col);
int					ft_find_color2(t_all *all, double cpt, int col, float door);
int					ft_find_color3(t_all *all, double cpt, double col,
						double angle);
void				cpy_sprite_infos(t_raycast *rc);
void				register_sprite(t_ray *ray, t_player p);
void				print_sprites(t_all *all, int x);
void				print_stickman(t_all *all);
void				print_square(t_all *all);

#endif
