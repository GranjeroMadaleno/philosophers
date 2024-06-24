# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andefern <andefern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:37:30 by andefern          #+#    #+#              #
#    Updated: 2024/05/20 12:10:26 by andefern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NOMBRE PROGRAMA #
NAME = libft.a

# FLAGS DE COMPILACION #
CC = gcc
CFLAGS = #-Wall -Wextra -Werror #-g3 -fsanitize=address
AR = ar rc
RM = /bin/rm -rf

# ARCHIVOS #
SRCS =	ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_utils.c \
		ft_utils2.c \
		ft_printf.c

# OBJETOS (*.o) #
OBJS = $(SRCS:.c=.o)

# MAKEFILE ART #
# COLORS #
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

# VARIABLE DE ENTORNO #
define LIBFT
$(MAG)
██╗     ██╗██████╗ ███████╗████████╗
██║     ██║██╔══██╗██╔════╝╚══██╔══╝
██║     ██║██████╔╝█████╗     ██║   
██║     ██║██╔══██╗██╔══╝     ██║   
███████╗██║██████╔╝██║        ██║   
╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝   
$(END)                                    
endef
export LIBFT

# REGLAS #
.SILENT:

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@
	
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)


clean:
	$(RM) $(OBJS)
	echo "objs deleted"

fclean: clean
	$(RM) $(NAME)
	echo "executable deleted"

re: fclean all

.PHONY: all clean fclean re
