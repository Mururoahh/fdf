#*** VARIABLES ***#

NAME			=	fdf

#FILES

SRCS			=	main.c			fdf.c		\
					draw_line.c		draw_map.c	\
					matrices.c		vector.c	\
					keys.c

UTILS			=	ft_iatoi.c		ft_isdigit.c

PARS			=	parser.c

GNL				=	get_next_line.c	get_next_line_utils.c

FILES			=	$(SRCS)								\
					$(addprefix $(DIR_UTILS), $(UTILS))	\
					$(addprefix $(DIR_GNL), $(GNL))		\
					$(addprefix $(DIR_PARS), $(PARS))

HEAD			=	fdf.h

OBJS			=	$(FILES:%.c=$(DIR_OBJS)%.o)

#DIRECTORIES

DIR_SRCS		=	srcs/

DIR_PARS		=	parser/

DIR_UTILS		=	utils/

DIR_GNL			=	gnl/

DIR_MLX			=	mlx/

DIR_HEAD		=	includes/

DIR_OBJS		=	.objs/

DIR				=	$(DIR_UTILS) $(DIR_GNL) $(DIR_PARS)

#ARBORESCENCE

ARB_OBJS		=	$(addprefix $(DIR_OBJS), $(DIR))

#PATH

PATH_HEAD		=	$(addprefix $(DIR_HEAD), $(HEAD))

#COMPIL

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address

MLXFLAG			=	-Lmlx -lmlx -framework OpenGL -framework Appkit

#COMMANDS

RM				=	rm -rf

MKDIR			=	mkdir -p

LDB				=	lldb

#*** RULES ***#

all				:	$(NAME)

run				:	all
					./fdf test_maps/42.fdf

$(NAME)			:	$(OBJS) $(PATH_HEAD) Makefile
					$(CC) $(CFLAGS) $(MLXFLAG) $(OBJS) -o $(NAME)

debug			:	$(OBJS) $(PATH_HEAD) Makefile
					$(CC) $(CFLAGS) $(MLXFLAG) $(OBJS) -o $(NAME)
					$(LDB) ./$(NAME)

lldb			:	$(LDB) ./$(NAME)

#COMPIL

$(DIR_OBJS)%.o	:	$(DIR_SRCS)%.c $(PATH_HEAD) Makefile | $(DIR_OBJS)
					$(CC) $(CFLAGS) -I$(DIR_HEAD) -I$(DIR_MLX) -g3 -c $< -o $@

$(DIR_OBJS)		:
					$(MKDIR) $(ARB_OBJS)

#CLEAN

clean			:
					$(RM) $(DIR_OBJS)

fclean			:	clean
					$(RM) $(NAME)

re				:
					make fclean
					make all
