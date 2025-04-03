# Nome do executável
TARGET = ex2_listaFinal

# Arquivos fonte
SRC = ex2_listaFinal.c bib_string.c

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
