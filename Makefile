# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andefern <andefern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 10:43:41 by andefern          #+#    #+#              #
#    Updated: 2024/10/14 13:51:13 by andefern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGAM NAME
NAME = philo

# COMPILATON FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I includes #-fsanitize=address
RM = /bin/rm -rf

# INCLUDE
INCLUDE = philo.h

# FILES TO COMPILE
SRCS =	srcs/actions.c		\
		srcs/eraser.c		\
		srcs/main.c			\
		srcs/parse.c		\
		srcs/time.c			\
		srcs/utils.c

#OBJECTS (*.o)
OBJS = $(SRCS:.c=.o)

# ASCII COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

# MAKEFILE ART #
define PHILOSOPHERS
$(YELLOW)

██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗
██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝
██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗
██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║
██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝
                                                                                                                                                                                                                                                                                  
$(END)
endef
export PHILOSOPHERS

#RULES
# .SILENT:

.o:.c $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
#	mv srcs/libft/libft.a .
#	-L./srcs/libft -lft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$$PHILOSOPHERS"

sanitize:
	$(eval CFLAGS+=-fsanitize=address -g3)

sani: sanitize all

sunny: sani

clean:
	$(RM) $(OBJS)
	echo "objects removed"

fclean: clean
	$(RM) $(NAME)
	echo "executable removed"

re: fclean all

lele: fclean all

.PHONY: all clean fclean re sani sanitize sunny lele