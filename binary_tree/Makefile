NAME = libtree.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
AR = ar rcus
FILES = ft_create_node \
		ft_insert_cnode \
		ft_insert_node \
		ft_find_node \
		ft_delete_cnode \
		ft_delete_node

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
