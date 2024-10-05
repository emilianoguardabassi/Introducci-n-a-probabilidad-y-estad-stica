#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXSIZE 4

/*
 * Este programa se encarga de darte algún ejercicio de las 4 guías 
 * de manera pseudoaleatoria para que puedas practicar para el parcial.
*/

int* init_array() {
    int *a = malloc(MAXSIZE * sizeof(int)); // Usar MAXSIZE
    if (a == NULL) {
        fprintf(stderr, "ERROR: malloc failed\n");
        return NULL;
    }
    a[0] = 18;
    a[1] = 17;
    a[2] = 16;
    a[3] = 10;
    return a;
}

unsigned int get_random_from_urandom() {
    int urandom_fd = open("/dev/urandom", O_RDONLY);
    if (urandom_fd < 0) {
        perror("ERROR: open /dev/urandom failed\n");
        exit(EXIT_FAILURE);
    }
    unsigned int random_value;
    if (read(urandom_fd, &random_value, sizeof(random_value)) < 0) {
        perror("ERROR: reading from /dev/urandom failed\n");
        close(urandom_fd);
        exit(EXIT_FAILURE);
    }
    close(urandom_fd);
    return random_value;
}

int main() {
    int *a = init_array();
    if (a == NULL) {
        return EXIT_FAILURE;
    }

    int random = get_random_from_urandom() % MAXSIZE;
    int choice = get_random_from_urandom() % (a[random] + 1);

    printf("Guía %d, ejercicio %d\n", random + 1, choice);

    free(a);

    return EXIT_FAILURE;
}

