#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:58:46 by glourdel          #+#    #+#              #
#    Updated: 2015/01/22 14:26:06 by glourdel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all a re clean fclean depend sources libft
.SUFFIXES:

export CC = gcc
NAME = fractol
FLAGS = -Wall -Wextra -Werror -pthread -O3

OFILES = $(notdir $(CFILES:.c=.o))

CFILES= \
		/ft_clean_prog.c \
		/ft_colors.c \
		/ft_draw_julia.c \
		/ft_draw_mandelbrot.c \
		/ft_errors.c \
		/ft_hooks.c \
		/ft_keypr_hook.c \
		/ft_loop.c \
		/ft_mlx_fill_pix.c \
		/ft_mlx_getcolor.c \
		/ft_mlx_gotopix.c \
		/ft_render.c \
		/ft_threads.c \
		/ft_tools.c \
		/ft_zoom.c \
		/main.c \


SRCDIR = src/

SRC = $(addprefix $(SRCDIR),$(CFILES))

OBJDIR = obj/

OBJ = $(addprefix $(OBJDIR),$(OFILES))

INCL_FLAGS = -Iinclude -Ilibft/include
CFLAGS = $(INCL_FLAGS) $(FLAGS)
LDFLAGS = -Llibft -lft -L/usr/X11/lib -lmlx -lXext -lX11 -lm

BLUE = "\033[34;1;3m"
GREEN = "\033[32m"
IGREEN = "\033[30;42m"
RED = "\033[31m"
IRED = "\033[0;37;41m"
BRED = "\033[31;1m"
END = "\033[0m"

all: libft $(NAME)

a: all clean

$(NAME): libft/libft.a $(OBJ)
	@/bin/echo "";
	@echo $(BLUE)"    === Linking $@..."$(END);
	@/bin/echo "";
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

libft:
	@make -C libft

fclean: clean
	@make -C libft $@
	@/bin/rm -f $(NAME)
	@echo $(BRED)"    === Removing "$(NAME)$(END)

clean:
	@/bin/rm -f $(OBJ)
	@echo $(RED)"    --> Removing .o files"$(END)
	@make -C libft $@

sclean:
	@/bin/rm -f $(OBJ)
	@echo $(RED)"    --> Removing .o files"$(END)

re:	fclean all

r:	sclean all


obj/ft_clean_prog.o: src//ft_clean_prog.c include/fractol.h \
 include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_clean_prog.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_clean_prog.o \
-c -fPIC $(SRCDIR)/ft_clean_prog.c $(CFLAGS)

obj/ft_colors.o: src//ft_colors.c
	@echo "\033[32m    --> Creating obj/ft_colors.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_colors.o \
-c -fPIC $(SRCDIR)/ft_colors.c $(CFLAGS)

obj/ft_draw_julia.o: src//ft_draw_julia.c include/fractol.h \
 include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_draw_julia.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_draw_julia.o \
-c -fPIC $(SRCDIR)/ft_draw_julia.c $(CFLAGS)

obj/ft_draw_mandelbrot.o: src//ft_draw_mandelbrot.c include/fractol.h \
 include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_draw_mandelbrot.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_draw_mandelbrot.o \
-c -fPIC $(SRCDIR)/ft_draw_mandelbrot.c $(CFLAGS)

obj/ft_errors.o: src//ft_errors.c libft/include/libft.h \
 libft/include/libft_types.h
	@echo "\033[32m    --> Creating obj/ft_errors.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_errors.o \
-c -fPIC $(SRCDIR)/ft_errors.c $(CFLAGS)

obj/ft_hooks.o: src//ft_hooks.c include/fractol.h include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_hooks.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_hooks.o \
-c -fPIC $(SRCDIR)/ft_hooks.c $(CFLAGS)

obj/ft_keypr_hook.o: src//ft_keypr_hook.c include/fractol.h \
 include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_keypr_hook.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_keypr_hook.o \
-c -fPIC $(SRCDIR)/ft_keypr_hook.c $(CFLAGS)

obj/ft_loop.o: src//ft_loop.c include/fractol.h include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_loop.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_loop.o \
-c -fPIC $(SRCDIR)/ft_loop.c $(CFLAGS)

obj/ft_mlx_fill_pix.o: src//ft_mlx_fill_pix.c include/fractol.h \
 include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_mlx_fill_pix.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_mlx_fill_pix.o \
-c -fPIC $(SRCDIR)/ft_mlx_fill_pix.c $(CFLAGS)

obj/ft_mlx_getcolor.o: src//ft_mlx_getcolor.c libft/include/libft.h \
 libft/include/libft_types.h
	@echo "\033[32m    --> Creating obj/ft_mlx_getcolor.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_mlx_getcolor.o \
-c -fPIC $(SRCDIR)/ft_mlx_getcolor.c $(CFLAGS)

obj/ft_mlx_gotopix.o: src//ft_mlx_gotopix.c include/fractol.h \
 include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_mlx_gotopix.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_mlx_gotopix.o \
-c -fPIC $(SRCDIR)/ft_mlx_gotopix.c $(CFLAGS)

obj/ft_render.o: src//ft_render.c include/fractol.h include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_render.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_render.o \
-c -fPIC $(SRCDIR)/ft_render.c $(CFLAGS)

obj/ft_threads.o: src//ft_threads.c include/fractol.h include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_threads.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_threads.o \
-c -fPIC $(SRCDIR)/ft_threads.c $(CFLAGS)

obj/ft_tools.o: src//ft_tools.c include/fractol.h include/fractol_types.h \
 libft/include/libft.h libft/include/libft_types.h
	@echo "\033[32m    --> Creating obj/ft_tools.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_tools.o \
-c -fPIC $(SRCDIR)/ft_tools.c $(CFLAGS)

obj/ft_zoom.o: src//ft_zoom.c include/fractol.h include/fractol_types.h
	@echo "\033[32m    --> Creating obj/ft_zoom.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)ft_zoom.o \
-c -fPIC $(SRCDIR)/ft_zoom.c $(CFLAGS)

obj/main.o: src//main.c include/fractol.h include/fractol_types.h
	@echo "\033[32m    --> Creating obj/main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)main.o \
-c -fPIC $(SRCDIR)/main.c $(CFLAGS)

