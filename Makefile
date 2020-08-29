# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baylak <baylak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 21:46:02 by npetrell          #+#    #+#              #
#    Updated: 2020/08/29 13:01:08 by baylak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

GCC = gcc -O2 -Wall -Wextra -Werror 

LIBFT = libft

FT_PRINTF = ft_printf

LFLAG = -L $(LIBFT) -lft

PRINT_FLAG = -L $(FT_PRINTF) -lftprintf

SRCS = main.c parse_options.c parse_folders.c utils.c linkedlistutils.c \
		inits.c print_dir.c print_file.c sort_by_ascii.c sort_by_time.c clear.c \
		print_attrib/display_attr.c \
		print_attrib/link_print.c  print_attrib/display_extend_attr.c \
		print_attrib/print_rights.c  print_attrib/print_time.c \
		print_attrib/print_user_group.c \


HEADERS = libft/

PRINTF_HEAD = ft_printf/

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
			@make -C $(FT_PRINTF)
			@$(GCC) -I $(INCLUDE) -o $(NAME) $(OBJ) $(LFLAG) $(PRINT_FLAG)
$(DIR)%.o: %.c
	@mkdir -p $(DIR)
	@mkdir -p $(DIR)/print_attrib
	@$(GCC) -I $(HEADERS) -I $(PRINTF_HEAD) -I $(INCLUDE) -o $@ -c $<
#Clean only Objects
clean:
	@rm -rf $(DIR)
	@make -C $(LIBFT) clean
	@make -C $(FT_PRINTF) clean

#Clean objects and execution files
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(FT_PRINTF) fclean
re: fclean all

.PHONY: all clean fclean re
