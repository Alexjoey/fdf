# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amylle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 11:58:06 by amylle            #+#    #+#              #
#    Updated: 2024/02/27 14:42:07 by amylle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= ./srcs
INC_DIR	= ./includes
OBJ_DIR	= ./obj

SRCS	= ./srcs/main.c ./srcs/error.c ./srcs/map_parser.c ./srcs/hooks.c ./srcs/ft_drawmap.c ./srcs/ft_project.c
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CC		= cc
CFLAGS	=
tCFLAGS	= -Wextra -Wall -Werror -g
INCLUDE	= -Llibft -lft -I$(INC_DIR) -Lmlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz
RM		= rm -rf
LIBFT	= libft/libft.a
MAKEFLAGS += --no-print-directory
NAME	= fdf

#---------------------------Messages--------------------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m


all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@ 

$(LIBFT):
		@make -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
				@echo Compiling $(NAME)
				@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)

clean:	
				@echo "$(BOLD_YELLOW)Removing all object files and directories"
				$(RM) $(OBJ_DIR)
				@make clean -C ./libft

fclean:
				@echo "$(BOLD_YELLOW)Removing binaries"
				$(RM) $(NAME) $(OBJ_DIR)
				@make fclean -C ./libft

re:			fclean all
