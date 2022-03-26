# Project file
NAME = Cub3d

# Operation system
OS		= $(shell uname)

# Project builds
SRCDIR		= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC		= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ		= $(SRC:.c=.o)
DEP		= $(OBJS:.o=.d)
INC		= ./inc/
BUILDDIR	= ./build/
DEPENDSDIR	= ./dep/
BUILDOBJS	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))
BUILDDEPS	= $(BUILDOBJS:.o=.d)

# Libft builds and dirs
LIBDIR		= ./libft/
LIBFT		= ./libft/libft.a
LIBINC		= ./libft/

# Optimization and compiler flags
CC		= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD

# Debug flag
DEBUG		= -g

# Mlx builds and dirs
ifeq ($(OS), Linux)
	MLXDIR		= ./minilibx-linux/
	MLX		= ./minilibx-linux/libmlx.a
	MLXINC		= ./minilibx-linux/
	MLXFLAGS	= -lmlx -lm -lX11 -lXext
else
	MLXDIR		= ./mlx-mac/
	MLX		= ./mlx-mac/libmlx.a
	MLXINC		= ./mlx-mac/
	MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
endif

# Main rule
all:	 $(BUILDDIR) $(LIBFT) $(MLX) $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) -I$(LIBINC) -I$(MLXINC) -I$(INC) $(CFLAGS) -g -o $@ -c $<

# Libft make
$(LIBFT):
	@make -C $(LIBDIR)

# MLX make
$(MLX):
	git submodule init
	git submodule update
	@make -C $(MLXDIR) 2>/dev/null
	@echo "\t\t MLX is builtin'"

#Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) $(BUILDOBJS) $(MLX) $(MLXFLAGS) $(DEBUG) $(CFLAGS) -o $(NAME)

# Cleaning up the build files
clean:
	@$(RM) $(BUILDOBJS)
	$(RM) $(BUILDDEPS)

	@make -C $(LIBDIR) clean
	@make -C $(MLXDIR) clean


# Getting rid of the project file
fclean: clean
	@$(RM) $(NAME)
	$(RM) -rf $(BUILDDIR)
	@make -C $(LIBDIR) fclean


# Do both of the above
re: fclean all

include $(wildcard $(DEP))

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
