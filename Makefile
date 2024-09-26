# Nome do executável
NAME = so_long

# Compilador e flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Diretórios de inclusão de headers
INCLUDES = -Iinclude -Ilibft -Imlx

# Diretório dos arquivos fonte
SRCDIR = src
INCDIR = include
LIBFTDIR = libft
MLXDIR = mlx

# Arquivos fonte e objetos
SRCS = $(SRCDIR)/so_long.c \
	   $(SRCDIR)/utils/memory.c \
       $(SRCDIR)/utils/error_checking.c \
	   $(SRCDIR)/utils/input_validation.c \
	   $(SRCDIR)/map/parse_map.c \
	   $(SRCDIR)/game/game.c \
	   $(SRCDIR)/game/render.c \
	   $(SRCDIR)/map/draw_map.c \
	   $(SRCDIR)/utils/utils.c \
	   $(SRCDIR)/game/check_game.c

OBJS = $(SRCS:.c=.o)

# Nome da biblioteca libft
LIBFT = $(LIBFTDIR)/libft.a

# Nome da biblioteca mlx
MLX = $(MLXDIR)/libmlx.a

# Flags para a MiniLibX
MLXFLAGS = -L$(MLXDIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Regra principal para compilar o projeto
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) -L$(LIBFTDIR) -lft

# Compilar a libft
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# Compilar a mlx
$(MLX):
	$(MAKE) -C $(MLXDIR)

# Regra para criar os arquivos objeto (.o)
%.o: %.c $(INCDIR)/so_long.h $(LIBFTDIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Limpa os arquivos objeto
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)

# Limpa os arquivos objeto e o executável
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

# Recompila o projeto do zero
re: fclean $(NAME)
