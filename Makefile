# Nome do seu executável
TARGET = libft.a

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = ./includes

# Listas de arquivos fonte para cada módulo
FT_PRINTF_SRCS = $(wildcard ft_printf/*.c)
GET_NEXT_LINE_SRCS = $(wildcard get_next_line/*.c)
LIBFT_SRCS = $(wildcard libft/*.c)

# Lista de objetos gerados para cada módulo
FT_PRINTF_OBJS = $(patsubst %.c, $(OBJ_DIR)/ft_printf/%.o, $(notdir $(FT_PRINTF_SRCS)))
GET_NEXT_LINE_OBJS = $(patsubst %.c, $(OBJ_DIR)/get_next_line/%.o, $(notdir $(GET_NEXT_LINE_SRCS)))
LIBFT_OBJS = $(patsubst %.c, $(OBJ_DIR)/libft/%.o, $(notdir $(LIBFT_SRCS)))

# Flags de compilação e bibliotecas
CC = gcc
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)
LDFLAGS = -Llibft -lft

# Regras de compilação
all: $(TARGET)

$(TARGET): $(FT_PRINTF_OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/ft_printf/%.o: ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: get_next_line/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Criação dos diretórios de objetos
$(shell mkdir -p $(OBJ_DIR)/ft_printf $(OBJ_DIR)/get_next_line $(OBJ_DIR)/libft)

# Limpeza dos objetos e do executável
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
