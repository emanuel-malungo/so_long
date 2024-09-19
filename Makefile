# Nome do executável
NAME = so_long

# Compilador e flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Diretórios de inclusão de headers
INCLUDES = -Iinclude -Ilibft

# Diretório dos arquivos fonte
SRCDIR = src
INCDIR = include
LIBFTDIR = libft

# Arquivos fonte e objetos
SRCS = $(SRCDIR)/so_long.c \
       $(SRCDIR)/utils/error_handling.c \
	   $(SRCDIR)/map/parse_map.c \
	   $(SRCDIR)/utils/memory.c \
	   $(SRCDIR)/utils/string_utils.c

OBJS = $(SRCS:.c=.o)

# Nome da biblioteca libft
LIBFT = $(LIBFTDIR)/libft.a

# Regra principal para compilar o projeto
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

# Compilar a libft
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

# Regra para criar os arquivos objeto (.o)
%.o: %.c $(INCDIR)/so_long.h $(LIBFTDIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Limpa os arquivos objeto
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)

# Limpa os arquivos objeto e o executável
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

# Recompila o projeto do zero
re: fclean $(NAME)
