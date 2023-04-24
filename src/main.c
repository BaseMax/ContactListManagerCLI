#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Clear terminal screeen (Linux/macOS)
    if ( system("clear") != 0) {
        printf("Error occurred when clear screen!\n"); 
    }
    if (puts("Hello world!") == EOF) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
