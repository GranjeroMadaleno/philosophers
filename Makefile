# PROGAM NAME
NAME = xylophoners

# COMPILATON FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

# INCLUDE
INCLUDE = xylophoners.h

# FILES TO COMPILE
SRCS =	srcs/actions.c		\
		srcs/adagio.c		\
		srcs/eraser.c		\
		srcs/initializer.c	\
		srcs/main.c			\
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
define XYLOPHONERS
$(GREEN)

██   ██ ██    ██ ██       ██████  ██████  ██   ██  ██████  ███    ██ ███████ ██████  ███████ 
 ██ ██   ██  ██  ██      ██    ██ ██   ██ ██   ██ ██    ██ ████   ██ ██      ██   ██ ██      
  ███     ████   ██      ██    ██ ██████  ███████ ██    ██ ██ ██  ██ █████   ██████  ███████ 
 ██ ██     ██    ██      ██    ██ ██      ██   ██ ██    ██ ██  ██ ██ ██      ██   ██      ██ 
██   ██    ██    ███████  ██████  ██      ██   ██  ██████  ██   ████ ███████ ██   ██ ███████ 
                                                                                             
                                                                                             
$(END)
endef
export XYLOPHONERS

#RULES
# .SILENT:

.c.o: $(SRCS)
	$(CC) -I includes $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
#	mv srcs/libft/libft.a .
#	-L./srcs/libft -lft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$$XYLOPHONERS"

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

.PHONY: all clean fclean re sani sanitize sunny