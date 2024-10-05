# Nombre del archivo ejecutable
EXEC = practice

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -std=c99

# Archivos fuente
SRCS = practice.c

# Archivos objeto generados
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regla para compilar los archivos .c en archivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados
clean:
	rm -f $(OBJS) $(EXEC)

# Regla para forzar la recompilación
rebuild: clean all

