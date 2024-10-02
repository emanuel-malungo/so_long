NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft -Imlx

SRCDIR = src
INCDIR = include
LIBFTDIR = libft
MLXDIR = mlx

SRCS = $(SRCDIR)/so_long.c \
	   $(SRCDIR)/utils.c \
       $(SRCDIR)/map_validation.c \
	   $(SRCDIR)/input_validation.c \
	   $(SRCDIR)/parse_map.c \
	   $(SRCDIR)/game.c \
	   $(SRCDIR)/render.c \
	   $(SRCDIR)/check_collection.c \
	   $(SRCDIR)/player_movement.c \
	   $(SRCDIR)/check_path_map.c

OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a
MLXFLAGS = -L$(MLXDIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) -L$(LIBFTDIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

%.o: %.c $(INCDIR)/so_long.h $(LIBFTDIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean $(NAME)
