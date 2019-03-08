# include libprintf.mk

# # directories
# SRC_DIR  := ./src
# INC_DIR  := ./includes
# OBJ_DIR  := ./obj
# TEST_DIR := ./test

# # src / obj files
# SRC		:=	main.c \
# 			pf_setup.c \
# 			pf_populate.c \
# 			pf_format.c \

# OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# # compiler
# CC		:= gcc
# CFLAGS	:= -Wall -Wextra -Werror
# CFLAGS	+= -O3 -march=native -pipe

# NAME	:= $(PRINTF_NAME)

# # rules
# all: $(NAME)

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)
# 	mkdir -p $(OBJ_DIR)/util
# 	mkdir -p $(OBJ_DIR)/handlers

# $(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) $(LIB_INC) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	ar rc $(PRINTF_NAME) $(OBJ)
# 	ranlib $(PRINTF_NAME)

# test:
# 	@$(MAKE) -C $(TEST_DIR) --no-print-directory

# clean:
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm -f $(PRINTF_NAME)

# re:
# 	@$(MAKE) fclean --no-print-directory
# 	@$(MAKE) all --no-print-directory

# .PHONY: all clean fclean re relibs test

# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2016/09/21 14:58:27 by zmagauin          #+#    #+#              #
# #    Updated: 2019/03/07 15:24:26 by zmagauin         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# NAME		= libftprintf.a
# CFLAGS		= -I libft/ -c
# FILES		=	main.c \
# 				pf_setup.c \
# 				pf_populate.c \
# 				pf_format.c

# OBJ			= $(FILES:%.c=%.o)

# LIBFT = libft/libft.a

# all: $(NAME)

# $(LIBFT):
# 	@make -C libft

# $(NAME): $(OBJ)
# 	@ar rcs $(NAME) $(OBJ)

# $(OBJ): $(LIBFT) $(FILES)
# 	@gcc $(LIBFT) $(CFLAGS) $(FILES)

# clean:
# 	@rm -rf $(OBJ)
# 	@make -C libft clean

# fclean: clean
# 	@rm -rf $(NAME)
# 	@make -C libft fclean

# re: fclean all

# .PHONY: clean fclean all re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:58:27 by zmagauin          #+#    #+#              #
#    Updated: 2019/03/07 14:54:40 by zmagauin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# CFLAGS +=
CFLAGS += -I libft/

SRC =	main.c \
		pf_setup.c \
		pf_populate.c \
		pf_parse.c \
		pf_format.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
