# Nome do arquivo executável do teste
TEST_EXECUTABLE = run_test.out

# Diretórios dos arquivos-fonte
SRC_DIR ?= linked_list
TEST_DIR = $(SRC_DIR)/test

# Compilador e opções de compilação
CC = gcc
CFLAGS = -o

# Bibliotecas necessárias para o CUnit
LIBS = -lcunit

# Lista de arquivos de origem
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

# Gerar nomes de saída para arquivos objeto
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, %.o, $(SRC_FILES)) $(patsubst $(TEST_DIR)/%.c, %.o, $(TEST_FILES))

# Regra padrão para compilar os arquivos de origem
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $@ -c $<

%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $@ -c $<

# Regra para o alvo padrão
all: $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_EXECUTABLE) $^ $(LIBS)

# Regra para executar os testes
test: all
	./$(TEST_EXECUTABLE)

# Regra para limpar arquivos gerados
# clean:
# rm -f $(OBJ_FILES) $(TEST_EXECUTABLE)

clean:
	rm *.o

# Indique que 'test' é um alvo phony, ou seja, não gera um arquivo chamado 'test'
.PHONY: test