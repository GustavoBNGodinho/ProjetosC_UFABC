# Nome do executável
TARGET = ex1_listaFinal

# Arquivos fonte
SRC = ex1_listaFinal.c bib.c

# Arquivo de cabeçalho
HEADERS = bib.h

# Nome do compilador
CC = gcc

# Opções do compilador
CFLAGS = -Wall -Wextra -std=c11

# Regra padrão para compilar o programa
all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Limpa os arquivos compilados
clean:
	rm -f $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)
