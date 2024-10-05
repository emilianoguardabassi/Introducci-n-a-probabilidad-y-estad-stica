#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXSIZE 4

typedef struct {
    int guia;
    int ejercicios;
} Mytupla;

// Inicializa las tuplas
Mytupla* init_tupla() {
    Mytupla *a = malloc(MAXSIZE * sizeof(Mytupla)); // Usar MAXSIZE
    if (a == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        return NULL;
    }

    // Inicializar las tuplas
    a[0].guia = 1;
    a[0].ejercicios = 18;

    a[1].guia = 2;
    a[1].ejercicios = 17;

    a[2].guia = 3;
    a[2].ejercicios = 16;

    a[3].guia = 4;
    a[3].ejercicios = 10;

    return a;
}

// Función para obtener un número aleatorio de /dev/urandom
unsigned int get_random_from_urandom() {
    int urandom_fd = open("/dev/urandom", O_RDONLY);
    if (urandom_fd < 0) {
        perror("Error al abrir /dev/urandom");
        exit(1);
    }
    unsigned int random_value;
    if (read(urandom_fd, &random_value, sizeof(random_value)) < 0) {
        perror("Error al leer de /dev/urandom");
        close(urandom_fd);
        exit(1);
    }
    close(urandom_fd);
    return random_value;
}

int main() {
    // Inicializar las tuplas
    Mytupla *a = init_tupla();
    if (a == NULL) {
        return 1; // Salir si hay un error en la asignación de memoria
    }

    // Seleccionar una guía aleatoria usando /dev/urandom
    int random = get_random_from_urandom() % MAXSIZE;

    // Seleccionar un ejercicio aleatorio de la guía seleccionada usando /dev/urandom
    int choice = get_random_from_urandom() % (a[random].ejercicios + 1);

    // Imprimir los resultados
    printf("Guía %d, ejercicio %d\n", a[random].guia, choice);

    // Liberar la memoria asignada
    free(a);

    return 0;
}

