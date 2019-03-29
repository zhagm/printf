# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 15:09:36 by zmagauin          #+#    #+#              #
#    Updated: 2019/03/28 12:41:53 by zmagauin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC	= 	pf_format.c \
		pf_parse.c \
		pf_populate.c \
		ft_printf.c \
		pf_setup.c \

OBJ = *.o

INC = -I libft/ -I includes/

LIBFT =	libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@gcc -c -Wall -Wextra $(INC) -c $^

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean

# NAME = libftprintf.a

# CFLAGS += 
# CFLAGS += -I libft/

# SRC =	main.c \
# 		pf_setup.c \
# 		pf_populate.c \
# 		pf_parse.c \
# 		pf_format.c \

# OBJ = $(SRC:.c=.o)

# LIBFT = libft/libft.a

# .PHONY = all clean fclean clean re

# all: $(NAME)

# $(OBJ): %.o: %.c
# 	@gcc -c $(CFLAGS) $< -o $@

# $(LIBFT):
# 	@make -C libft

# $(NAME): $(LIBFT) $(OBJ)
# 	@gcc $(OBJ) $(LIBFT) -o $(NAME)

# clean:
# 	@rm -rf $(OBJ)
# 	@make -C libft clean

# fclean: clean
# 	@rm -rf $(NAME)
# 	@make -C libft fclean

# re: fclean all