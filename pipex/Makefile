# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajemraou <ajemraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 00:06:27 by ajemraou          #+#    #+#              #
#    Updated: 2022/02/22 00:06:31 by ajemraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_check_arg.c \
	  t_strjoin.c \
	  pipex.c \
	  store_arg.c \
	  ft_strlen.c \
	  ft_split.c \
	  ft_strdup.c \
	  main.c

BNS = ft_strjoin_bonus.c \
	  get_next_line_bonus.c \
	  get_next_line_utils_bonus.c \
	  here_doc_bonus.c \
	  main_bonus.c \
	  pipex_bonus.c \
	  pipex_utils_bonus.c \
	  ft_strlen_bonus.c \
	  ft_split_bonus.c \
	  ft_putendl_fd_bonus.c \
	  ft_strdup_bonus.c \
	  store_arg_bonus.c

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

OBJCT = ${SRC:.c=.o}

BNS_OBJ = ${BNS:.c=.o}

LIB = libpipex.a

all : $(NAME)
$(NAME): $(OBJCT)
	@$(CC) $(CFLAGS) $(OBJCT) -o $(NAME)
	@printf "\033[0;32m-->pipex...\033[0m\n"

bonus : $(LIB)
$(LIB) : $(BNS_OBJ)
	@ar -rc $(LIB) $(BNS_OBJ)
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME)
	@printf "\033[0;34m-->pipex_bonus...\033[0m\n"

clean :
	@rm -f $(OBJCT) $(BNS_OBJ) $(LIB)
	@printf "\033[0;31m-->Deleted...\033[0m\n"

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all re bonus flcean clean