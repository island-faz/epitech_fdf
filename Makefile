##
## Makefile for Makefile in /home/bourhi_a/rendu/Piscine-C-lib/my
## 
## Made by bourhime amine
## Login   <bourhi_a@epitech.net>
## 
## Started on  Mon Oct 21 11:02:20 2013 bourhime amine
## Last update Sun Dec  8 18:09:40 2013 bourhime amine
##

SRC		= 	lib/my_getnbr.c \
			lib/my_putstr.c \
			lib/my_putchar.c \
			lib/my_str_to_wordtab.c \
			fdf_functions/draw_line.c \
			fdf_functions/put_pixel_in_image.c \
			lib/get_next_line.c \
			fdf_functions/rotate.c \
			fdf_functions/my_realloc.c \
			fdf_functions/cal_border.c \
			fdf_functions/draw_fdf.c \
			fdf_functions/animate.c \
			fdf_functions/manage_key.c \
			fdf_functions/gere_expose.c \
			fdf_functions/clear_image.c \
			fdf_functions/get_map.c \
			fdf_functions/calc_projection.c \
			fdf_functions/run_fdf.c \
			main.c \

OBJ		=	$(SRC:.c=.o)

MINILIBX	=	minilibx

NAME		=	fdf

CC		=	cc

CFLAGS		=	-Werror -ansi -pedantic -Wextra

HOST		=	$(HOSTTYPE)

RM		=	rm -f

LDFLAGS		=	-lm -L/usr/lib64 -L./minilibx -lmlx -L/usr/lib64/X11 -lXext -lX11

BCP		=	*~

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MINILIBX)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C $(MINILIBX)
	$(RM) $(OBJ) $(BCP) fdf_functions/$(BCP) lib/$(BCP) include/$(BCP)

fclean:	clean
	make fclean -C $(MINILIBX)
	$(RM) $(NAME)

re:	fclean all
