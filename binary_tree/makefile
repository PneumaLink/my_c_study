NAME = libtree.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
AR = ar rcus
FILES = ft_newnode \
		ft_addnode \
		ft_findnode

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c .o : $(SRCS)
	$(CC) $(CFLAGS) -c -0 $@ $<

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) a.out

re : fclean all
