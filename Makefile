# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = includes

# Listas de arquivos fonte para cada módulo
FT_PRINTF_SRCS = $(wildcard ft_printf/*.c)
GET_NEXT_LINE_SRCS = $(wildcard get_next_line/*.c)
LIBFT_SRCS = $(wildcard libft/*.c)

# Lista de objetos gerados para cada módulo
FT_PRINTF_OBJS = $(patsubst %.c, $(OBJ_DIR)/ft_printf/%.o, $(notdir $(FT_PRINTF_SRCS)))
GET_NEXT_LINE_OBJS = $(patsubst %.c, $(OBJ_DIR)/get_next_line/%.o, $(notdir $(GET_NEXT_LINE_SRCS)))
LIBFT_OBJS = $(patsubst %.c, $(OBJ_DIR)/libft/%.o, $(notdir $(LIBFT_SRCS)))

# Nome da biblioteca estática
TARGET = libft.a

# Flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

# Regra padrão
all: $(TARGET)

# Regras de compilação dos objetos para cada módulo
$(OBJ_DIR)/ft_printf/%.o: ft_printf/%.c | $(OBJ_DIR)/ft_printf
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: get_next_line/%.c | $(OBJ_DIR)/get_next_line
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libft/%.o: libft/%.c | $(OBJ_DIR)/libft
	$(CC) $(CFLAGS) -c $< -o $@

# Criação dos diretórios de objetos
$(OBJ_DIR)/ft_printf:
	mkdir -p $@

$(OBJ_DIR)/get_next_line:
	mkdir -p $@

$(OBJ_DIR)/libft:
	mkdir -p $@

# Regra para criar a biblioteca estática
$(TARGET): $(FT_PRINTF_OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT_OBJS)
	ar rcs $@ $^

# Alvo para limpar os objetos
clean:
	rm -rf $(OBJ_DIR)

.PHONY: all clean
