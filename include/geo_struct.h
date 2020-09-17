/*
** geo_struct.h for FDF in /home/bourhi_a/rendu/igraph/tp0
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Nov 10 06:52:09 2013 bourhime amine
** Last update Thu Dec 12 02:11:55 2013 
*/

#ifndef		        GEO_STRUCT_H_
# define		GEO_STRUCT_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"

# define EMPTY_MAP		"Empty map, bad !\n"
# define MISSING_MAP		"Map is missing, bad !\n"
# define BAD_FILE_FORMAT	"Bad file format, bad !\n"
# define ABS(x)			((((x)) < 0) ? (-(x)) : ((x)))
# define HEIGHT			900
# define WIDTH			1500
# define CT1			0.55
# define CT2			0.55
# define KeyPressMask		(1L<<0)
# define KeyPress		2
# define TRANS_SPEED		20
# define GREEN_COLOR		0x33FF00
# define ROTATE_X_LEFT_KEY	65431
# define ROTATE_X_RIGHT_KEY	65437
# define ZOOM_IN_KEY		65451
# define ZOOM_OUT_KEY		65453
# define MOVE_UP_KEY		65362
# define MOVE_RIGHT_KEY		65363
# define MOVE_DOWN_KEY		65364
# define MOVE_LEFT_KEY		65361
# define ROTATE_Y_LEFT_KEY	65429
# define ROTATE_Y_RIGHT_KEY	65434
# define ROTATE_Z_LEFT_KEY	65430
# define ROTATE_Z_RIGHT_KEY	65432
# define RESET_KEY		65293
# define EXTEND_Z_KEY		65436
# define REDUCE_Z_KEY		65435
# define EXIT_KEY		65307
# define ANIMATE_KEY_Z		97
# define ANIMATE_KEY_X		122
# define ANIMATE_KEY_Y	        101

typedef struct	s_array
{
  int		**array;
  int		i;
  int		j;
}		t_array;

typedef struct	s_angle
{
  float		x;
  float		y;
  float		z;
}		t_angle;

typedef struct	s_ops
{
  int		zoom;
  int		trans_x;
  int		trans_y;
  int		z;
}		t_ops;

typedef struct	s_point
{
  int		x;
  int		y;
  int		z;
}		t_point;

typedef struct  s_my_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
}		t_graphics;

typedef struct	s_image
{
  int		bpp;
  int		sizeline;
  int		*data;
  int		endian;
  int		end;
}		t_image;

typedef struct	s_fdf
{
  t_graphics	*p;
  t_array	map;
  t_image	*img;
  t_angle	angle;
  t_ops		ops;
}		t_fdf;

int		my_strlen(char*);
void		my_putchar(char);
int		my_getnbr(char *a);
void		draw_line(t_point p1, t_point p2, t_image *img, int color);
void		put_pixel_in_image(t_point p, t_image *img, int color);
void		my_putchar(char);
int		my_putstr(char *);
char		**my_str_to_wordtab(char *);
void		rotate(t_point *, float angl_x, float angl_y, float angl_z);
void		animate(int key, t_fdf *fdf);
t_array		my_realloc(t_array *arr, char *line, int n);
t_point		cal_border(t_array *arr, t_angle angle, t_ops ops);
void		draw_fdf(t_fdf *fdf);
int		manage_key(int key, void *p);
int		gere_expose(void *p);
void		clear_image(int	*img, int end);
t_array		get_map(int fd);
void		calc_projection(t_point *p1, t_point *p2);
int		run_fdf(t_fdf *fdf, int fd);
int		project_and_draw(t_point p1, t_point p2, t_fdf *, t_point);
void		perror(const char *s);
void		animate(int key, t_fdf *fdf);

#endif		/* GEO_STRUCT_H_ */
