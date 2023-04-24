#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Clear terminal screeen (Linux/macOS)
#ifdef _WIN32
    if (system("cls") != 0) {
        printf("Error occurred when clear screen!\n"); 
    }
#else
    if (system("clear") != 0) {
        printf("Error occurred when clear screen!\n");
    }
#endif
    if (puts("Contact List Manager") == EOF) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
