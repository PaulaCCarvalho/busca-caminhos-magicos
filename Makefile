# Nome do compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -g

# Diretório dos arquivos fonte
SRC_DIR = src

# Nome do executável
TARGET = main

# Lista dos arquivos fonte
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/heap.c $(SRC_DIR)/graph.c $(SRC_DIR)/dijkstra.c

# Lista dos arquivos objeto gerados
OBJS = $(SRCS:.c=.o)

# Regras para construir o executável
all: $(TARGET)

# Regra para compilar o código fonte em arquivos objeto
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regras para compilar cada arquivo .c em um arquivo .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para executar a aplicação
run: $(TARGET)
	./$(TARGET) $(ARGS)

# Limpeza dos arquivos objeto e do executável
clean:
	rm -f $(TARGET) $(OBJS)
