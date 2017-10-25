# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 14:06:14 by pilespin          #+#    #+#              #
#    Updated: 2016/10/14 11:40:55 by pilespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all

NAME	=	philo

SDIR	=	src/
HDIR	=	includes/
ODIR	=	object/
FOLDER	=	-I $(HDIR) -I./$(LIB_SDL)/include

LIB_SDL = libsdl
PATH_SDL = SDL2-2.0.3
# SDL_CHECK = $(LIB_SDL)/include/SDL2/SDL.h
SDL = `./$(LIB_SDL)/bin/sdl2-config --cflags --libs`

SRCA	=	project.c \
			init.c \
			algo_action.c \
			algo_core.c \
			draw_sdl.c \
			draw_shell.c \

SRCH	=	project.h \
			struct.h \

SRCO	=	$(SRCA:.c=.o)

CC		=	gcc
LIB		=	-L ./libft/ -lft #-pthread
FLAGS	=	-Wall -Wextra -Werror

SRC 	=	$(patsubst %.c, $(SDIR)%.c, $(SRCA))
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(SRCH))
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(SRCA))

all: sdl $(NAME)

no: $(NAME)

sdl:
	@echo "\033[32mCompiling SDL ...\033[0m" ; make -C ./libft
	@mkdir -p $(LIB_SDL)
	@tar -xf $(PATH_SDL).tar.gz
	@cd $(PATH_SDL) && ./configure --prefix=`cd ../$(LIB_SDL) && pwd` && make && make install

$(NAME): $(OBJ) $(SRC)
	@echo "\033[32m compiling libft >>> \c \033[0m" ; make -C ./libft
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB) $(FOLDER) $(SDL)
	@echo "\033[37m END $(NAME)\033[0m"

$(ODIR)%.o: $(SDIR)%.c $(HDR)
	@mkdir -p $(ODIR)
	@$(CC) -c $< -o $@ $(FLAGS) $(FOLDER) -pthread
	@echo "\033[32m ok \033[33m $@\033[0m"

clean:
	@make -C ./libft clean
	@rm -rf $(ODIR)
	@rm -rf $(PATH_SDL)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@rm -rf $(LIB_SDL)

re: fclean all
