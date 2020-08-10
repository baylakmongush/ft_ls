# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baylak <baylak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 21:46:02 by npetrell          #+#    #+#              #
#    Updated: 2020/08/10 21:28:33 by baylak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

GCC = gcc -Wall -Wextra -Werror 

LIBFT = libft

LFLAG = -L $(LIBFT) -lft

SRCS = main.c parse.c\

HEADERS = libft/

INCLUDE = includes/

DIR_SRC = srcs/

DIR = objects/

OBJS = $(SRCS:%.c=%.o)

vpath %.c srcs/
vpath %.h includes/
SRC = $(addprefix $(DIR_SRC),$(SRCS))
OBJ = $(addprefix $(DIR),$(OBJS))

all: $(NAME)

#Compile

$(NAME): $(OBJ)
			@make -C $(LIBFT)
			@$(GCC) -I $(INCLUDE) -o $(NAME) $(OBJ) $(LFLAG)
$(DIR)%.o: %.c
	@mkdir -p $(DIR)
	@$(GCC) -I $(HEADERS) -I $(INCLUDE) -o $@ -c $<
#Clean only Objects
clean:
	@rm -rf $(DIR)
	@make -C $(LIBFT) clean

#Clean objects and execution files
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean
re: fclean all

.PHONY: all clean fclean re
