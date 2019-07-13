#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:49:25 by ssoraka           #+#    #+#              #
#    Updated: 2019/03/11 20:57:23 by ssoraka          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CHECKER = checker
PUSHSWAP = push_swap
LIB = $(LIBSRC)libft.a
HEADER = ./includes/
LIBSRC = ./libft/
SRC1 = ./sources/
SRC = command_push.c \
command_swap_rot.c \
is_sorted.c \
lists.c \
min_med_max.c \
opt_rotation.c \
print.c \
validation.c

OBJS = $(SRC:.c=.o)

.PHONY: clean all fclean re

all: $(CHECKER) $(PUSHSWAP)

$(CHECKER): $(LIB) $(OBJS) $(CHECKER).o
	$(CC) $(CFLAGS) -o $@ $^

$(PUSHSWAP): $(LIB) $(OBJS) $(PUSHSWAP).o
	$(CC) $(CFLAGS) -o $(PUSHSWAP) $(PUSHSWAP).o $(OBJS) $(LIB)

$(LIB):
	@make lib_refresh

%.o: $(SRC1)%.c
	$(CC) $(CFLAGS) -c $< -I $(HEADER) -I $(LIBSRC)

lib_refresh:
	make -C $(LIBSRC)

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -rf $(OBJS) $(PUSHSWAP).o $(CHECKER).o
	@make -C $(LIBSRC) clean

fclean: clean
	@rm -rf $(PUSHSWAP) $(CHECKER)
	make -C $(LIBSRC) fclean

re: fclean all
