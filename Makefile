#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glourdel <glourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:58:46 by glourdel          #+#    #+#              #
#    Updated: 2015/01/20 14:01:34 by glourdel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all a re clean fclean depend sources libft
.SUFFIXES:

export CC = gcc
NAME = fractol
FLAGS = -Wall -Wextra -Werror -ggdb

OFILES = $(notdir $(CFILES:.c=.o))

CFILES= \
		/main.c \


SRCDIR = src/

SRC = $(addprefix $(SRCDIR),$(CFILES))

OBJDIR = obj/

OBJ = $(addprefix $(OBJDIR),$(OFILES))

INCL_FLAGS = -Iinclude -Ilibft/include
CFLAGS = $(INCL_FLAGS) $(FLAGS)
LDFLAGS = -Llibft -lft

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


obj/main.o: src//main.c libft/include/libft.h libft/include/libft_types.h
	@echo "\033[32m    --> Creating obj/main.o ...\033[0m"
	@mkdir -p $(OBJDIR);
	@$(CC) -o $(OBJDIR)main.o \
-c -fPIC $(SRCDIR)/main.c $(CFLAGS)

