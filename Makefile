#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:58:46 by glourdel          #+#    #+#              #
#    Updated: 2015/01/20 17:13:51 by glourdel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all a re clean fclean depend sources libft
.SUFFIXES:

export CC = gcc
NAME = fractol
FLAGS = -Wall -Wextra -Werror -ggdb

OFILES = $(notdir $(CFILES:.c=.o))

CFILES= \
		/ft_clean_prog.c \
		/ft_errors.c \
		/ft_hooks.c \
		/ft_keypr_hook.c \
		/ft_loop.c \
		/ft_mlx_fill_pix.c \
		/ft_mlx_getcolor.c \
		/ft_mlx_gotopix.c \
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

obj/main.o: src//main.c include/fractol.h include/fractol_types.h
	@echo "\033[32m    --> Creating obj/main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)main.o \
-c -fPIC $(SRCDIR)/main.c $(CFLAGS)

